
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

#include <gtypes/CatmullRomSpline2.h>
#include <gtypes/Vector2.h>

#include <gtypes/CatmullRomSpline3.h>
#include <gtypes/Vector3.h>

#include <gtypes/Matrix4.h>

#include <iostream>

/* screen width, height, and bit depth */
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

/* Setup our booleans */
#define TRUE  1
#define FALSE 0

	///////////////////
	
	gtypes::CatmullRomSpline3 splajn;
    float curv = 0.0;
    int segment = 1;
	
	///////////////////
	
GLdouble vecpos;
GLdouble angle;
gtypes::Matrix4 cam;

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
    gluPerspective( 45.0f, ratio, 0.1f, 1000.0f );

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
    case SDLK_v:
        angle += 1.0;
        break;
    case SDLK_b:
        angle -= 1.0;
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
    
    vecpos += 0.00002;
	if(vecpos > 1.0)
	{
		vecpos = 0.0;
	}

    glLoadIdentity( );
    
    gtypes::Vector3 pos = splajn.calcPosition(vecpos);
    gtypes::Vector3 tan = splajn.calcTangent(vecpos);
    gtypes::Vector3 nor = splajn.calcNormal(vecpos);
    gtypes::Vector3 binor;
    binor.cross(tan, nor);
    
    cam[0] = binor.x; cam[4] = nor.x; cam[8]  =   -tan.x; cam[12] = pos.x;
    cam[1] = binor.y; cam[5] = nor.y; cam[9]  =   -tan.y; cam[13] = pos.y;
    cam[2] = binor.z; cam[6] = nor.z; cam[10] =   -tan.z; cam[14] = pos.z;
    cam[3] =     0.0; cam[7] =   0.0; cam[11] =     0.0; cam[15] = 1.0;
    cam.inverse();
    
    glLoadMatrixf(cam);
    
    
	//glTranslatef(0.0, 0.0, -25.0);
    //glRotatef(angle, 0.0, 1.0, 0.0);

    glBegin(GL_LINE_STRIP);
        for(int i = 1; i < splajn._points.size() - 2; ++i)
        {
            for(double t = 0; t <= 1; t += 0.01)
            {
                gtypes::Vector3 vc = splajn._calcSegmentPosition(t, i);
                glVertex3f(vc.x, vc.y, vc.z);
            }
        }
    glEnd();
    
    for(int i = 0; i < splajn._points.size(); ++i)
    {
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 1.0);
            gtypes::Vector3 v = splajn._points[i];
            glVertex3f(v.x + 0.1, v.y + 0.1, v.z);
            glVertex3f(v.x + 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y + 0.1, v.z);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 1.0);
            v = splajn._points[i];
            glVertex3f(v.x + 0.1, v.y + 0.1, v.z);
            glVertex3f(v.x + 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y + 0.1, v.z);
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
            v = splajn._points[i];
            glVertex3f(v.x, v.y + 0.2, v.z);
            glVertex3f(v.x + 0.2, v.y, v.z);
            glVertex3f(v.x, v.y - 0.2, v.z);
            glVertex3f(v.x - 0.2, v.y, v.z);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            v = splajn._points[i];
            glVertex3f(v.x, v.y + 0.2, v.z);
            glVertex3f(v.x + 0.2, v.y, v.z);
            glVertex3f(v.x, v.y - 0.2, v.z);
            glVertex3f(v.x - 0.2, v.y, v.z);
        glEnd();
    }
    
    glLineWidth(3.0);
    glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
        gtypes::Vector3 v = splajn.calcPosition(vecpos);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x + 0.2, v.y + 0.2, v.z);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x + 0.2, v.y - 0.2, v.z);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x - 0.2, v.y - 0.2, v.z);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x - 0.2, v.y + 0.2, v.z);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(v.x, v.y, v.z);
        glVertex3f(v.x + 2*tan.x, v.y + 2*tan.y, v.z);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(v.x, v.y, v.z);
        glVertex3f(v.x + 2*nor.x, v.y + 2*nor.y, v.z);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(v.x, v.y, v.z);
        glVertex3f(v.x + 2*binor.x, v.y + 2*binor.y, v.z + 2*binor.z);
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
    */
    
    glLoadIdentity();
    glTranslatef(12,9,-35);
    
    glBegin(GL_LINE_STRIP);
        for(int i = 1; i < splajn._points.size() - 2; ++i)
        {
            for(double t = 0; t <= 1; t += 0.01)
            {
                gtypes::Vector3 vc = splajn._calcSegmentPosition(t, i);
                glVertex3f(vc.x, vc.y, vc.z);
            }
        }
    glEnd();
    
    glLineWidth(3.0);
    glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
        v = splajn.calcPosition(vecpos);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x + 0.2, v.y + 0.2, v.z);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x + 0.2, v.y - 0.2, v.z);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x - 0.2, v.y - 0.2, v.z);
        glVertex3f(v.x, v.y, v.z);
		glVertex3f(v.x - 0.2, v.y + 0.2, v.z);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(v.x, v.y, v.z);
        glVertex3f(v.x + 2*tan.x, v.y + 2*tan.y, v.z);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(v.x, v.y, v.z);
        glVertex3f(v.x + 2*nor.x, v.y + 2*nor.y, v.z);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(v.x, v.y, v.z);
        glVertex3f(v.x + 2*binor.x, v.y + 2*binor.y, v.z + 2*binor.z);
	glEnd();
    glLineWidth(1.0);
    
    for(int i = 0; i < splajn._points.size(); ++i)
    {
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 1.0);
            gtypes::Vector3 v = splajn._points[i];
            glVertex3f(v.x + 0.1, v.y + 0.1, v.z);
            glVertex3f(v.x + 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y + 0.1, v.z);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 1.0);
            v = splajn._points[i];
            glVertex3f(v.x + 0.1, v.y + 0.1, v.z);
            glVertex3f(v.x + 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y - 0.1, v.z);
            glVertex3f(v.x - 0.1, v.y + 0.1, v.z);
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
            v = splajn._points[i];
            glVertex3f(v.x, v.y + 0.2, v.z);
            glVertex3f(v.x + 0.2, v.y, v.z);
            glVertex3f(v.x, v.y - 0.2, v.z);
            glVertex3f(v.x - 0.2, v.y, v.z);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            v = splajn._points[i];
            glVertex3f(v.x, v.y + 0.2, v.z);
            glVertex3f(v.x + 0.2, v.y, v.z);
            glVertex3f(v.x, v.y - 0.2, v.z);
            glVertex3f(v.x - 0.2, v.y, v.z);
        glEnd();
    }
    
    

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );

    /* Gather our frames per second */
    Frames++;
    {
	GLint t = SDL_GetTicks();
	if (t - T0 >= 5000) {
	    GLfloat seconds = (t - T0) / 1000.0;
	    GLfloat fps = Frames / seconds;
	    printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
	    T0 = t;
	    Frames = 0;
	}
    }

    return( TRUE );
}

int main( int argc, char **argv )
{
	/////////////////////////////
    
    vecpos = 0.0;
    
    //splajn.addPoint(-6.0, -2.0, 0.0);
    
    splajn.addPoint(-8.0, 2.0, 0.0);
    splajn.addPoint(-6.0, 1.0, 0.0);
    splajn.addPoint(0.0, 4.0, 0.0);
	splajn.addPoint(2.0, 0.0, 0.0);
    splajn.addPoint( 4.0, -4.0, 2.0);
    splajn.addPoint(-2.0, -5.0, -6.0);
    splajn.addPoint(-6.0, -2.0, 0.0);
    splajn.addPoint(-8.0, -1.0, 1.0);
    
    //splajn.addPoint(-6.0, 1.0, 0.0);
    //splajn.addPoint(0.0, 4.0, 0.0);
    
    splajn.resample(8);
    splajn.subdivide(2);
    
	
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
