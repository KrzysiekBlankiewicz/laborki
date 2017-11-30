
#include <gtk/gtk.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

GtkWidget *przycisk[8][8];

void createBoard(char board[][8])
{
    int w = 0, h = 0; //w - width, h-height
    //*(*(board + 1) + 2) = '7';
    for(; w < 8; w++)
    {
        for(h = 0; h < 8; h++)
        {
            board[w][h] = ' ';
            //puts("ok\n");
        }//for
    }//for
}//funkcja

int lightOne(char board[][8], int x, int y)
{
    //printf("%d %d\n", x, y);
    if(board[x][y] == '1'|| board[x][y] == '*'|| board[x][y] == 'X') return 0;
    for(int i = x+1; (i < 8) && (board[i][y] != 'X'); i++)
    {
            board[i][y] = '1';
            //printf("%d %d\n", i, y);
    }
    for(int i = x-1; (i >=0) && (board[i][y] != 'X'); i--)
    {
            board[i][y] = '1';
            //printf("%d %d\n", i, y);
    }
    for(int i = y+1; (i < 8)&&(board[x][i] != 'X'); i++)
    {
            board[x][i] = '1';
            //printf("%d %d\n", x, i);
    }
    for(int i = y-1; (i >= 0)&& (board[x][i] != 'X'); i--)
    {
            board[x][i] = '1';
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
    for(int i = 0; i < 10; i++)
    {
        board[rand()%8][rand()%8] = 'X';
    }
    return 1;
}

void wcisk(GtkWidget *widget)
{
    printf("%d\n", abs(widget - przycisk[1][0]));
    //if(widget - przycisk[0][0] == 1) puts("ok\n");
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
    {
        gtk_button_set_label(GTK_BUTTON(widget), "*");
        //gtk_button_set_label(GTK_BUTTON(widget+1), "*");
    }
    else
    gtk_button_set_label(GTK_BUTTON(widget), " ");
}

int main (int argc, char *argv[])
{
    int w = 0, h = 0;
    char board[8][8];//createBoard(board);

    createBoard(board);
    blocks(board);
    lightAll(board);

    GtkWidget *okno;
    GtkWidget *kontener;

    GtkWidget *table;

    gtk_init (&argc, &argv);

    okno = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size (GTK_WINDOW(okno), 300, 200);
    gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);// ustawia okno na środku
    gtk_window_set_title(GTK_WINDOW(okno), "AKARI"); //zmienia tytuł okna

    table = gtk_table_new(8, 8, TRUE);

    for(w = 0; w < 8; w++)//czysci przyciski
    {
        for(h = 0; h < 8; h++)
        {
            przycisk[w][h] = gtk_toggle_button_new_with_label(" ");
        }//for
    }//for


    for(w = 0; w < 8; w++)//dopisuje X gdzie trzeba
    {
        for(h = 0; h < 8; h++)
        {
            if(board[w][h]=='*') przycisk[w][h] = gtk_toggle_button_new_with_label ("*");
            if(board[w][h]=='X') przycisk[w][h] = gtk_toggle_button_new_with_label ("X");
            if(board[w][h]=='1') przycisk[w][h] = gtk_toggle_button_new_with_label ("1");
        }//for
    }//for

    for (int x = 0; x < 8; x++)//dołącza przyciski do tabeli
        for (int y = 0; y < 8; y++)
            gtk_table_attach_defaults (GTK_TABLE(table), przycisk[y][x], x, x+1, y, y+1);

    gtk_container_add(GTK_CONTAINER(okno), table);

    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            g_signal_connect(przycisk[i][j], "clicked", G_CALLBACK(wcisk), NULL);
        }//for
    }//for
;
    gtk_widget_show_all (okno); //wyświetl
    gtk_main ();
    return 0;
}//main
