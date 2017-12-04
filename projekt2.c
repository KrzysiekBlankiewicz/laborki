
#include<gtk/gtk.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

GtkWidget *przycisk[8][8];
GtkWidget *table;
int countedStars[8][8];

void createBoard(char board[][8])
{
    int w = 0, h = 0; //w - width, h-height
    //*(*(board + 1) + 2) = '7';
    for(; w < 8; w++)
    {
        for(h = 0; h < 8; h++)
        {
            board[w][h] = ' ';
            countedStars[w][h] = 0;
            //puts("ok\n");
        }//for
    }//for
}//funkcja

int lightOne(char board[][8], int x, int y)
{
    //printf("%d %d\n", x, y);
    if(board[x][y] == '+'|| board[x][y] == '*'|| board[x][y] == 'X') return 0;
    for(int i = x+1; (i < 8) && (board[i][y] != 'X'); i++)
    {
            board[i][y] = '+';
            //printf("%d %d\n", i, y);
    }
    for(int i = x-1; (i >=0) && (board[i][y] != 'X'); i--)
    {
            board[i][y] = '+';
            //printf("%d %d\n", i, y);
    }
    for(int i = y+1; (i < 8)&&(board[x][i] != 'X'); i++)
    {
            board[x][i] = '+';
            //printf("%d %d\n", x, i);
    }
    for(int i = y-1; (i >= 0)&& (board[x][i] != 'X'); i--)
    {
            board[x][i] = '+';
            //printf("%d %d\n", x, i);
    }
    board[x][y] = '*';
    //puts("\n");
    return 1;
}

int lightAll(char board[8][8])
{
    srand(time(NULL));
    int lightedBulbs = 0;//liczba zapalonych zarowek
    int darkFields = 1;
    while(lightedBulbs < 6)
    {
        lightedBulbs += lightOne(board, rand()%8, rand()%8);
    }
    do
    {
        darkFields = 0;
        for(int j = 0; j < 64; j++)
        {
            if(board[j/8][j%8] == ' ') darkFields++;
            //printf("%d ", darkFields);
        }
        if(darkFields > 0){lightOne(board, rand()%8, rand()%8);}
    }
    while(darkFields > 0);

    return 1;
}

int blocks(char board[][8])
{
    srand(time(NULL));
    for(int i = 0; i < 25; i++)
    {
        board[rand()%8][rand()%8] = 'X';
    }
    return 1;
}

void countStars(char board[8][8])
{
    int counter;
    for(int w = 0; w < 8; w++)
    {
        for(int h = 0; h < 8; h++)
        {
            if(board[w][h] == 'X')
            {
                counter = 0;
                if((board[w+1][h] == '*' )&&(w != 7)) counter++;
                if((board[w-1][h] == '*')&&(w != 0)) counter++;
                if((board[w][h+1] == '*')&&(h != 7)) counter++;
                if((board[w][h-1] == '*')&&(h != 0)) counter++;

                countedStars[w][h] = counter;
            }
            //puts("ok\n");
        }//for
    }//for

}

void fillWithLight(GtkWidget *button)
{
    int help = 0, v, q;//pomaga w wyjściu z pętli
    for(v = 0; v < 8; v++)//szukam v, q będących współrzędnymi button
    {
        for(q = 0; q < 8; q++)
        {
            if(button - przycisk[v][q] == 0)
            {
                help = 1;
                break;
            }
        }
        if(help == 1) break;
    }

    //printf("%d %d\n", v, q);

    for(int i = v+1; i < 8; i++)
    {
        if(gtk_widget_get_name(przycisk[i][q])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[i][q]), "+");
    }
    for(int i = v-1; i >= 0; i--)
    {
        if(gtk_widget_get_name(przycisk[i][q])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[i][q]), "+");
    }
    for(int i = q+1; i < 8; i++)
    {
        if(gtk_widget_get_name(przycisk[v][i])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[v][i]), "+");
    }
    for(int i = q-1; i >= 0; i--)
    {
        if(gtk_widget_get_name(przycisk[v][i])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[v][i]), "+");
    }
}

void fillWithDarkness(GtkWidget *button)
{
    int help = 0, v, q;//pomaga w wyjściu z pętli
    for(v = 0; v < 8; v++)//szukam v, q będących współrzędnymi button
    {
        for(q = 0; q < 8; q++)
        {
            if(button - przycisk[v][q] == 0)
            {
                help = 1;
                break;
            }
        }
        if(help == 1) break;
    }

    //printf("%d %d\n", v, q);

    for(int i = v+1; i < 8; i++)
    {
        if(gtk_widget_get_name(przycisk[i][q])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[i][q]), " ");
    }
    for(int i = v-1; i >= 0; i--)
    {
        if(gtk_widget_get_name(przycisk[i][q])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[i][q]), " ");
    }
    for(int i = q+1; i < 8; i++)
    {
        if(gtk_widget_get_name(przycisk[v][i])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[v][i]), " ");
    }
    for(int i = q-1; i >= 0; i--)
    {
        if(gtk_widget_get_name(przycisk[v][i])[0] == 'X') break;
        gtk_button_set_label(GTK_BUTTON(przycisk[v][i]), " ");
    }
}

void pushed(GtkButton *widget)
{
    const gchar *text = gtk_button_get_label (widget);
    if(text[0] == '+')
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
        return;
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
    {
        gtk_button_set_label(GTK_BUTTON(widget), "*");
        gtk_widget_set_name(GTK_WIDGET(widget), "star");
        fillWithLight(GTK_WIDGET(widget));
    }
    else
    {
        gtk_button_set_label(GTK_BUTTON(widget), " ");
        gtk_widget_set_name(GTK_WIDGET(widget), " ");
        fillWithDarkness(GTK_WIDGET(widget));
    }
}

void fillWithX(char board[8][8])
{
    srand(time(NULL));
    int w = 0, h = 0;
    for(w = 0; w < 8; w++)//czysci przyciski
    {
        for(h = 0; h < 8; h++)
        {
            przycisk[w][h] = gtk_toggle_button_new_with_label(" ");
            gtk_widget_set_name(przycisk[w][h], " ");
        }//for
    }//for

    for(w = 0; w < 8; w++)//dopisuje X gdzie trzeba
    {
        for(h = 0; h < 8; h++)
        {
            //if(board[w][h]=='*') przycisk[w][h] = gtk_toggle_button_new_with_label ("*");
            if(board[w][h]=='X')
            {
                przycisk[w][h] = gtk_label_new("X");
                gtk_widget_set_name(przycisk[w][h], "X");
                //if(rand()%3 > 0)
                {
                    if(countedStars[w][h] == 0) gtk_label_set_text(przycisk[w][h], "0");
                    if(countedStars[w][h] == 1) gtk_label_set_text(przycisk[w][h], "1");
                    if(countedStars[w][h] == 2) gtk_label_set_text(przycisk[w][h], "2");
                    if(countedStars[w][h] == 3) gtk_label_set_text(przycisk[w][h], "3");
                    if(countedStars[w][h] == 4) gtk_label_set_text(przycisk[w][h], "4");
                }
            }
            //if(board[w][h]=='+') przycisk[w][h] = gtk_toggle_button_new_with_label ("+");
        }//for
    }//for

    for (int x = 0; x < 8; x++)//dołącza przyciski do tabeli
    {
        for (int y = 0; y < 8; y++)
        {
            gtk_table_attach_defaults (GTK_TABLE(table), przycisk[y][x], x, x+1, y, y+1);
        }
    }
}


void clear(GtkButton *widget, char board[8][8])
{
    int w, h;
    GdkColor color;
    gdk_color_parse ("black", &color);
    for(w = 0; w < 8; w++)//dopisuje X gdzie trzeba
    {
        for(h = 0; h < 8; h++)
        {
            if(board[w][h]=='*')
            {
                gtk_button_set_label(GTK_BUTTON(przycisk[w][h]), " ");
                gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(przycisk[w][h]), FALSE);
            }
            if(board[w][h]=='+')
            {
                gtk_button_set_label(GTK_BUTTON(przycisk[w][h]), " ");
                gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(przycisk[w][h]), FALSE);
            }
            gtk_widget_modify_fg (przycisk[w][h], GTK_STATE_NORMAL, &color);
        }//for
    }//for
}

void fatality(gpointer okno)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(okno), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Niestety...");
    gtk_window_set_title(GTK_WINDOW(dialog), "Błąd");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void great(gpointer okno)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(okno), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_OTHER, GTK_BUTTONS_OK, "Brawo!");
    gtk_window_set_title(GTK_WINDOW(dialog), "Wygrana");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_main_quit();
}

void check(GtkWidget *something, GtkWidget *okno)
{
    int w, h, counter = 0;
    for(w = 0; w < 8; w++)//dopisuje X gdzie trzeba
    {
        for(h = 0; h < 8; h++)
        {
            if(gtk_widget_get_name(przycisk[w][h])[0] == 'X')
            {
                    counter = 0;
                    //if((gtk_widget_get_name(przycisk[w-1][h-1])[0] == 's') && (w != 0) && (h != 0)) counter++;
                    if((w != 0)&&(gtk_widget_get_name(przycisk[w-1][h])[0] == 's')) counter++;
                    //if((gtk_widget_get_name(przycisk[w-1][h+1])[0] == 's') && (w != 0) && (h != 7)) counter++;
                    if((h != 0)&&(gtk_widget_get_name(przycisk[w][h-1])[0] == 's')) counter++;
                    if((h != 7)&&(gtk_widget_get_name(przycisk[w][h+1])[0] == 's')) counter++;
                    //if((gtk_widget_get_name(przycisk[w+1][h-1])[0] == 's') && (w != 7) && (h != 0)) counter++;
                    if((w != 7)&&(gtk_widget_get_name(przycisk[w+1][h])[0] == 's')) counter++;
                    //if((gtk_widget_get_name(przycisk[w+1][h+1])[0] == 's') && (w != 7) && (h != 7)) counter++;
                    if(counter == countedStars[w][h])
                    {
                        GdkColor color;
                        gdk_color_parse ("black", &color);
                        gtk_widget_modify_fg (przycisk[w][h], GTK_STATE_NORMAL, &color);
                    }
                    if(counter != countedStars[w][h])
                    {
                        GdkColor color;
                        gdk_color_parse ("red", &color);
                        gtk_widget_modify_fg (przycisk[w][h], GTK_STATE_NORMAL, &color);

                        fatality(okno);
                        return;
                    }
            }
        }//for
    }//for
    great(okno);
}

void end(GtkWidget *something)
{
    gtk_main_quit();
}


int main (int argc, char *argv[])
{
    char board[8][8];//createBoard(board);

    createBoard(board);
    blocks(board);
    lightAll(board);
    countStars(board);

    GtkWidget *okno;
    GtkWidget *kontener1;
    GtkWidget *kontener2;
    GtkWidget *kontener3;
    GtkWidget *boks;

    gtk_init (&argc, &argv);

    okno = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size (GTK_WINDOW(okno), 300, 200);
    gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);// ustawia okno na środku
    gtk_window_set_title(GTK_WINDOW(okno), "AKARI"); //zmienia tytuł okna

    boks = gtk_vbox_new (FALSE, 1);
    table = gtk_table_new(8, 8, TRUE);
    kontener1 = gtk_button_new_with_label("Sprawdzam");
    kontener2 = gtk_button_new_with_label("Wyczyść");
    kontener3 = gtk_button_new_with_label("Zakończ");

    fillWithX(board);

    gtk_container_add(GTK_CONTAINER(boks), table);
    gtk_container_add(GTK_CONTAINER(boks), kontener1);
    gtk_container_add(GTK_CONTAINER(boks), kontener2);
    gtk_container_add(GTK_CONTAINER(boks), kontener3);
    gtk_container_add(GTK_CONTAINER(okno), boks);

    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(kontener2, "clicked", G_CALLBACK(clear), board);
    g_signal_connect(kontener1, "clicked", G_CALLBACK(check), okno);
    g_signal_connect(kontener3, "clicked", G_CALLBACK(end), okno);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] != 'X') g_signal_connect(przycisk[i][j], "clicked", G_CALLBACK(pushed), NULL);
        }//for
    }//for


    gtk_widget_show_all (okno); //wyświetl
    gtk_main ();
    return 0;
}//main
