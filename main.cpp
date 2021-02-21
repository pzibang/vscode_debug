#include <iostream>
#include <glib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node_t
{
    gchar key[32];
    gchar value[32];
}NODE_T;

NODE_T *create_node(char *key, char *value);
static void displayhash(gpointer key, gpointer value, gpointer user_data);
static void destroy_key(gpointer hash_data);
static void destroy_value(gpointer hash_data);


int main()
{
    char buff[32] = {0};
    static GHashTable *g_hash = NULL;

    g_hash = g_hash_table_new_full(g_str_hash, g_int_equal, destroy_key, destroy_value);

    NODE_T *node = create_node("name","xcy");
    if(node != NULL)
        g_hash_table_insert(g_hash, &node->key, &node->value);
    NODE_T *node1 = create_node("age","18");
    if(node1 != NULL)
        g_hash_table_insert(g_hash, &node1->key, &node1->value);
    NODE_T *node2 = create_node("sex","man");
    if(node2 != NULL)
        g_hash_table_insert(g_hash, &node2->key, &node2->value);
    NODE_T *node3 = create_node("id","00001");
    if(node3 != NULL)
        g_hash_table_insert(g_hash, &node3->key, &node3->value);
    
    memcpy(buff,"this is parm",12);
    if(NULL != g_hash) {
        g_hash_table_foreach(g_hash, displayhash, buff);
    }

    printf("------------------free hashtable------------------------\n");
    g_hash_table_destroy(g_hash); 
    return 0;
}

NODE_T *create_node(char *key, char *value)
{
    NODE_T *node = (NODE_T *)malloc(sizeof(NODE_T));
    if (NULL == node)
    {
        return node;
    }

    memset(node, 0, sizeof(NODE_T));
    strcpy(node->key, key);
    strcpy(node->value, value);
   
    return node;
}

static void displayhash(gpointer key, gpointer value, gpointer user_data)
{
    printf("user data: %s\n");
    printf("key:%s, value:%s\n", key, value);
}

static void destroy_key(gpointer hash_data)
{
    printf("destory key: %s\n", hash_data);
    memset(hash_data, 0, sizeof(hash_data));
}

static void destroy_value(gpointer hash_data)
{
    printf("destory value: %s\n", hash_data);
    memset(hash_data, 0, sizeof(hash_data));
}