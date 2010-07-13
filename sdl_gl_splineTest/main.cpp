
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

#include <gtypes/CatmullRomSpline2.h>
#include <gtypes/Vector2.h>

#include <iostream>

/* screen width, height, and bit depth */
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

/* Setup our booleans */
#define TRUE  1
#define FALSE 0

	///////////////////
	
	gtypes::CatmullRomSpline2 splajn;
    float curv = 0.0;
	
	///////////////////
	
GLdouble vecpos;

/* This is our SDL surface */
SDL_Surface *surface;

/* function to release/destroy our resources and restoring the old desktop */
void Quit( int returnCode )
{
    /* clean up the window */
    SDL_Quit( );

    /* and exit appropriately */
    exit( returnCode );
}

/* function to reset our viewport after a window resize */
int resizeWindow( int width, int height )
{
    /* Height / width ration */
    GLfloat ratio;

    /* Protect against a divide by zero */
    if ( height == 0 )
	height = 1;

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLint )width, ( GLint )height );

    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );

    return( TRUE );
}

/* function to handle key press events */
void handleKeyPress( SDL_keysym *keysym )
{
    switch ( keysym->sym )
	{
	case SDLK_ESCAPE:
	    /* ESC key was pressed */
	    Quit( 0 );
	    break;
	case SDLK_F1:
	    /* F1 key was pressed
	     * this toggles fullscreen mode
	     */
	    SDL_WM_ToggleFullScreen( surface );
	    break;
    case SDLK_a:
        curv += 0.05;
        break;
    case SDLK_s:
        curv -= 0.05;
        break;
	default:
	    break;
	}

    return;
}

/* general OpenGL initialization function */
int initGL()
{

    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );

    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );

    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    return( TRUE );
}

/* Here goes our drawing code */
int drawGLScene()
{
    /* These are to calculate our fps */
    static GLint T0     = 0;
    static GLint Frames = 0;

    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    //splajn.setCurvature(curv);
    
    vecpos += 0.0008;
	if(vecpos >= 1.0)
	{
		vecpos = 0.0;
	}

    glLoadIdentity( );
	glTranslatef(0.0, 0.0, -15.0);
	/*glLineWidth(5.0);
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		//for(int segment = 0; segment < splajn._numSegments; ++segment) {
			for(double i = 0.0; i < 1.0; i += 0.01) {
				gtypes::Vector2 vec = splajn.calcPosition(i);
				//gtypes::Vector2 vec = splajn._splineSegmentPosition(i / 100.0, splajn._segments[segment]);
				glVertex2f(vec.x, vec.y);
                std::cerr << "Vector: " << vec.x << ", " << vec.y << std::endl;
			}
		//}
	glEnd();*/
    
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		for(int segment = 0; segment < splajn._numSegments; ++segment) {
            switch(segment%3){
                case 0:
                    glColor3f(0.0, 1.0, 0.0);
                    break;
                case 1:
                    glColor3f( 0.0, 0.0, 1.0);
                    break;
                case 2:
                    glColor3f( 1.0, 0.0, 0.0);
                    break;
            }
			for(int i = 0; i <= 100; i++) {
				gtypes::Vector2 vec = splajn._calculateSegmentPosition(i / 100.0, splajn._segments[segment]);
				glVertex2f(vec.x, vec.y);
                //std::cerr << "Point: " << vec.x << ", " << vec.y << std::endl;
			}
		}
	glEnd();
    
    for(int i = 0; i < splajn._segments.size(); ++i)
    {
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 1.0);
            gtypes::Vector2 v = splajn._segments[i].v1;
            glVertex3f(v.x + 0.1, v.y + 0.1, 0);
            glVertex3f(v.x + 0.1, v.y - 0.1, 0);
            glVertex3f(v.x - 0.1, v.y - 0.1, 0);
            glVertex3f(v.x - 0.1, v.y + 0.1, 0);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 1.0);
            v = splajn._segments[i].v2;
            glVertex3f(v.x + 0.1, v.y + 0.1, 0);
            glVertex3f(v.x + 0.1, v.y - 0.1, 0);
            glVertex3f(v.x - 0.1, v.y - 0.1, 0);
            glVertex3f(v.x - 0.1, v.y + 0.1, 0);
        glEnd();
        
        switch(i%3){
                case 0:
                    glColor3f(0.0, 1.0, 0.0);
                    break;
                case 1:
                    glColor3f( 0.0, 0.0, 1.0);
                    break;
                case 2:
                    glColor3f( 1.0, 0.0, 0.0);
                    break;
        }
        
        glBegin(GL_LINE_LOOP);
            v = splajn._segments[i].v0;
            glVertex3f(v.x, v.y + 0.2, 0);
            glVertex3f(v.x + 0.2, v.y, 0);
            glVertex3f(v.x, v.y - 0.2, 0);
            glVertex3f(v.x - 0.2, v.y, 0);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            v = splajn._segments[i].v3;
            glVertex3f(v.x, v.y + 0.2, 0);
            glVertex3f(v.x + 0.2, v.y, 0);
            glVertex3f(v.x, v.y - 0.2, 0);
            glVertex3f(v.x - 0.2, v.y, 0);
        glEnd();
    }
    
    glLineWidth(2.0);
    glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
        gtypes::Vector2 v = splajn.calcPosition(vecpos);
        glVertex3f(v.x, v.y, 0);
		glVertex3f(v.x + 0.2, v.y + 0.2, 0);
        glVertex3f(v.x, v.y, 0);
		glVertex3f(v.x + 0.2, v.y - 0.2, 0);
        glVertex3f(v.x, v.y, 0);
		glVertex3f(v.x - 0.2, v.y - 0.2, 0);
        glVertex3f(v.x, v.y, 0);
		glVertex3f(v.x - 0.2, v.y + 0.2, 0);
	glEnd();
    glLineWidth(1.0);
    
    /*
	glBegin(GL_LINE_STRIP);
		glVertex2f(splajn.getPosition(vecpos).x, splajn.getPosition(vecpos).y);
		glVertex2f(splajn.getPosition(vecpos).x + splajn.getTangent(vecpos).x, splajn.getPosition(vecpos).y + splajn.getTangent(vecpos).y);
	glEnd();
	
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(splajn.getPosition(vecpos).x + splajn.getTangent(vecpos).x + 0.05, splajn.getPosition(vecpos).y + splajn.getTangent(vecpos).y + 0.05);
		glVertex2f(splajn.getPosition(vecpos).x + splajn.getTangent(vecpos).x + 0.05, splajn.getPosition(vecpos).y + splajn.getTangent(vecpos).y - 0.05);
		glVertex2f(splajn.getPosition(vecpos).x + splajn.getTangent(vecpos).x - 0.05, splajn.getPosition(vecpos).y + splajn.getTangent(vecpos).y - 0.05);
		glVertex2f(splajn.getPosition(vecpos).x + splajn.getTangent(vecpos).x - 0.05, splajn.getPosition(vecpos).y + splajn.getTangent(vecpos).y + 0.05);
	glEnd();
	
	std::cerr << "Tangenta: " << splajn.getTangent(vecpos).x << " , " << splajn.getTangent(vecpos).y << std::endl;
    */

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );

    /* Gather our frames per second */
    while(SDL_GetTicks() - T0 < 16);
    T0 = SDL_GetTicks();
    /*Frames++;
    {
	GLint t = SDL_GetTicks();
	if (t - T0 >= 5000) {
	    GLfloat seconds = (t - T0) / 1000.0;
	    GLfloat fps = Frames / seconds;
	    printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
	    T0 = t;
	    Frames = 0;
	}
    }*/

    return( TRUE );
}

int main( int argc, char **argv )
{
	/////////////////////////////
	
	splajn.setSamplingRate(10);
    splajn.setCurvature(0.5);
    splajn.setOrigin(-2.0, 0.0);
    splajn.addPoint(0.0, 2.0);
	splajn.addPoint(2.0, 0.0);
    splajn.addPoint(4.0, -1.0);
    splajn.addPoint(-2.0, -5.0);
    splajn.addPoint(-6.0, -2.0);
    splajn.closeSpline();
    splajn.rebuildSpline(48);
    splajn.closeSpline();
    
	
	/////////////////////////////
	
    /* Flags to pass to SDL_SetVideoMode */
    int videoFlags;
    /* main loop variable */
    int done = FALSE;
    /* used to collect events */
    SDL_Event event;
    /* this holds some info about our display */
    const SDL_VideoInfo *videoInfo;
    /* whether or not the window is active */
    int isActive = TRUE;

    /* initialize SDL */
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
	    fprintf( stderr, "Video initialization failed: %s\n",
		     SDL_GetError( ) );
	    Quit( 1 );
	}

    /* Fetch the video info */
    videoInfo = SDL_GetVideoInfo( );

    if ( !videoInfo )
	{
	    fprintf( stderr, "Video query failed: %s\n",
		     SDL_GetError( ) );
	    Quit( 1 );
	}

    /* the flags to pass to SDL_SetVideoMode */
    videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    videoFlags |= SDL_RESIZABLE;       /* Enable window resizing */

    /* This checks to see if surfaces can be stored in memory */
    if ( videoInfo->hw_available )
	videoFlags |= SDL_HWSURFACE;
    else
	videoFlags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    if ( videoInfo->blit_hw )
	videoFlags |= SDL_HWACCEL;

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* get a SDL surface */
    surface = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
				videoFlags );

    /* Verify there is a surface */
    if ( !surface )
	{
	    fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
	    Quit( 1 );
	}

    /* initialize OpenGL */
    if ( initGL( ) == FALSE )
	{
	    fprintf( stderr, "Could not initialize OpenGL.\n" );
	    Quit( 1 );
	}

    resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );
	
	GLint time = SDL_GetTicks();
    while ( !done )
	{
	    /* handle the events in the queue */

	    while ( SDL_PollEvent( &event ) )
		{
		    switch( event.type )
			{
			case SDL_ACTIVEEVENT:
			    /* Something's happend with our focus
			     * If we lost focus or we are iconified, we
			     * shouldn't draw the screen
			     */
			    if ( event.active.gain == 0 )
				isActive = FALSE;
			    else
				isActive = TRUE;
			    break;
			case SDL_VIDEORESIZE:
			    /* handle resize event */
			    surface = SDL_SetVideoMode( event.resize.w,
							event.resize.h,
							16, videoFlags );
			    if ( !surface )
				{
				    fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
				    Quit( 1 );
				}
			    resizeWindow( event.resize.w, event.resize.h );
			    break;
			case SDL_KEYDOWN:
			    /* handle key presses */
			    handleKeyPress( &event.key.keysym );
			    break;
			case SDL_QUIT:
			    /* handle quit requests */
			    done = TRUE;
			    break;
			default:
			    break;
			}
		}
		
	    if ( isActive )
		drawGLScene();
	}
    Quit( 0 );
    return( 0 );
}
