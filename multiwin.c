#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include <string.h>



void on_gtk_win_main_destroy(GtkWidget *);
void on_gtk_botao_sub_win1_press_event(GtkWidget *, GtkWidget *);
void on_gtk_botao_sub_win2_press_event(GtkWidget *, GtkWidget *);
void on_gtk_menu_win1_activate(GtkMenuItem *, GtkWidget *);
void on_gtk_menu_win2_activate(GtkMenuItem *, GtkWidget *);
void on_gtk_botao_fechar_qualquer_sub_win_press_event(GtkWidget *, GtkWidget *);


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *win_main; 
	GtkWidget 		*btn_sub_win1, *btn_sub_win2;
	GtkWidget 		*menu_win1, *menu_win2, *menu_sair;

 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainwin.ui", NULL);
		
	win_main = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_win_main"));
		
	btn_sub_win1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_botao_sub_win1")); 
    g_signal_connect(btn_sub_win1, "pressed", G_CALLBACK (on_gtk_botao_sub_win1_press_event), win_main);
	
	btn_sub_win2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_botao_sub_win2")); 
    g_signal_connect(btn_sub_win2, "pressed", G_CALLBACK (on_gtk_botao_sub_win2_press_event), win_main);
	
	menu_win1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_menu_win1")); 
    g_signal_connect(menu_win1, "activate", G_CALLBACK (on_gtk_menu_win1_activate), win_main);
	
	menu_win2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_menu_win2")); 
    g_signal_connect(menu_win2, "activate", G_CALLBACK (on_gtk_menu_win2_activate), win_main);
	
	menu_sair = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_menu_sair")); 
    g_signal_connect(menu_sair, "activate", G_CALLBACK (on_gtk_win_main_destroy), NULL);
	
	g_signal_connect(win_main, "destroy", G_CALLBACK (on_gtk_win_main_destroy), NULL);	
    
	gtk_builder_connect_signals(builder, NULL);
	
	g_object_unref(builder);
	 
    gtk_widget_show(win_main);

    gtk_main();

    return 0;
}
 


void on_gtk_win_main_destroy(GtkWidget *thisWin)
{
	gtk_main_quit();
} 

void on_gtk_botao_sub_win1_press_event(GtkWidget *thisButton, GtkWidget *win_main)
{
    GtkBuilder *builder;
	GtkWidget  *sub_win1, *btn_fechar_sub_win1;
	
	builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "subwin1.ui", NULL);
	sub_win1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_sub_win1"));
	 
	// gtk_window_set_transient_for(GTK_WINDOW(sub_win1), GTK_WINDOW(win_main));
	gtk_window_set_destroy_with_parent(GTK_WINDOW(sub_win1), TRUE); 
	
	btn_fechar_sub_win1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_botao_fechar_sub_win1")); 
	g_signal_connect(btn_fechar_sub_win1, "clicked", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win1);
	g_signal_connect(sub_win1, "destroy", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win1);
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	
	gtk_widget_show(sub_win1);
}

void on_gtk_menu_win1_activate(GtkMenuItem *thisMenuItem, GtkWidget *win_main)
{
    GtkBuilder *builder;
	GtkWidget  *sub_win1, *btn_fechar_sub_win1;
	
	builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "subwin1.ui", NULL);
	sub_win1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_sub_win1"));
	 
	// gtk_window_set_transient_for(GTK_WINDOW(sub_win1), GTK_WINDOW(win_main));
	gtk_window_set_destroy_with_parent(GTK_WINDOW(sub_win1), TRUE); 
	
	btn_fechar_sub_win1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_botao_fechar_sub_win1")); 
	g_signal_connect(btn_fechar_sub_win1, "clicked", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win1);
	g_signal_connect(sub_win1, "destroy", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win1);
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	
	gtk_widget_show(sub_win1);
}

void on_gtk_botao_sub_win2_press_event(GtkWidget *thisButton, GtkWidget *win_main)
{
    GtkBuilder *builder;
	GtkWidget  *sub_win2, *btn_fechar_sub_win2;
	
	builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "subwin2.ui", NULL);
	sub_win2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_sub_win2"));
	 
	gtk_window_set_transient_for(GTK_WINDOW(sub_win2), GTK_WINDOW(win_main));
	gtk_window_set_destroy_with_parent(GTK_WINDOW(sub_win2), TRUE); 
	
	btn_fechar_sub_win2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_botao_fechar_sub_win2")); 
	g_signal_connect(btn_fechar_sub_win2, "clicked", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win2);
	g_signal_connect(sub_win2, "destroy", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win2);
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	
	gtk_widget_show(sub_win2);
}

void on_gtk_menu_win2_activate(GtkMenuItem *thisMenuItem, GtkWidget *win_main)
{
    GtkBuilder *builder;
	GtkWidget  *sub_win2, *btn_fechar_sub_win2;
	
	builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "subwin2.ui", NULL);
	sub_win2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_sub_win2"));
	 
	gtk_window_set_transient_for(GTK_WINDOW(sub_win2), GTK_WINDOW(win_main));
	gtk_window_set_destroy_with_parent(GTK_WINDOW(sub_win2), TRUE); 
	
	btn_fechar_sub_win2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk_botao_fechar_sub_win2")); 
	g_signal_connect(btn_fechar_sub_win2, "clicked", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win2);
	g_signal_connect(sub_win2, "destroy", G_CALLBACK (on_gtk_botao_fechar_qualquer_sub_win_press_event), sub_win2);
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	
	gtk_widget_show(sub_win2);
	
}


void on_gtk_botao_fechar_qualquer_sub_win_press_event(GtkWidget *thisButton, GtkWidget *thisWin)
{
    gtk_widget_destroy(thisWin);
}

