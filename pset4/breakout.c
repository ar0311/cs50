//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// paddle dimensions
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 15

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    double move_x = drand48();
    double move_y = 2;
    
    if (drand48() < 0.5)
    {
        move_x = -move_x;
    }
    
    bool paused = true;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        if (paused)
        {
            waitForClick();
            paused = false;
        }
        // move ball
        move(ball, move_x, move_y);
        
        pause(5);
        
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL)
        {
            // mouse event happened, check for movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                int x = getX(event) - (PADDLE_WIDTH / 2);
                setLocation(paddle, x, HEIGHT - 20);                
            }
            
            if (getEventType(event) == MOUSE_CLICKED)
            {
                paused = !paused;
            }
        }
        
        GObject object = detectCollision(window, ball);
        
        if (object != NULL)
        {
            if (object == paddle)
            {
                move_y = -move_y;
            }
            else if (strcmp(getType(object), "GRect") == 0)
            {
                // hit brick
                move_y = -move_y;
                removeGWindow(window, object);
                points++;
                bricks--;
                
                updateScoreboard(window, label, points);
            }
        }
        
        if (getX(ball) <= 0)
        {
            // bounce off left
            move_x = -move_x;
        }
        else if (getX(ball) > (WIDTH - 20))
        {
            // bounce off right
            move_x = -move_x;
        }
        
        if (getY(ball) > HEIGHT)
        {
            // ball missed paddle
            removeGWindow(window, ball);
            lives--;
            ball = initBall(window);
            move_x = drand48();
            if (drand48() < 0.5)
            {
                move_x = -move_x;
            }
            paused = true;
         }
         
         if (getY(ball) < 0)
         {
            // bounce off top
            move_y = -move_y;
         }
    }
    
    if (lives > 0)
    {
        // win game
        setLabel(label, "WINNER");
        setColor(label, "GREEN");
    }
    else
    {
        // lose game
        setLabel(label, "LOSER");
        setColor(label, "RED");
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    string colours[5]; // ROWS is const, will need to recycle if necessary
    colours[0] = "RED";
    colours[1] = "BLUE";
    colours[2] = "GREEN";
    colours[3] = "YELLOW";
    colours[4] = "ORANGE";
    
    int x = 5;
    int y = 5;
    
    int brick_width = ((WIDTH - (COLS * 5)) / COLS) - 1;
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(x, y, brick_width, 10);
            setFilled(brick, true);
            setColor(brick, colours[i]);
            add(window, brick);
            
            x += brick_width + 5;
        }
        x = 5;
        y += 20;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH / 2, HEIGHT / 2, 20, 20);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect((WIDTH / 2) - (PADDLE_WIDTH / 2),
                            (HEIGHT - 20), PADDLE_WIDTH, PADDLE_HEIGHT);

    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    
    setColor(label, "BLUE");
    add(window, label);
    setLocation(label, ((getWidth(window) - getWidth(label)) / 2), ((getHeight(window) - getHeight(label)) / 2));
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
