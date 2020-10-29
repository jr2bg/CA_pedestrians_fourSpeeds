/*******************************************************************************/
#include <curses.h>
#include <string>

int main()
  {
  std::string lol = "####\n } <\n> <{\n  <>\n<< }\n####";
  std::string lol2 = "####\n  }<\n ><{\n <  \n<   \n####";
  char *hi= &lol[0];
  char users_name[ 100 ];

  initscr();
  //(void)echo();

  addstr( hi );
  refresh();
  getnstr( users_name, sizeof( users_name ) - 1 );

  /* Here is where we clear the screen.                  */
  /* (Remember, when using Curses, no change will appear */
  /* on the screen until <b>refresh</b>() is called.     */
  clear();

  printw( "Greetings and salutations %s!\n", users_name );
  refresh();

  printw( "\n\n\nPress ENTER to quit." );
  refresh();

  clear();
  hi = &lol2[0];
  addstr(hi);
  getnstr( users_name, sizeof( users_name ) - 1 );

  endwin();
  return 0;
  }
