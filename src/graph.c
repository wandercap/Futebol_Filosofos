#include <stdio.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/util.h"

void putSucessors(graph_p graph, list_node_p node, game_p game) {
  int i;
  plays_p f, o;

  f = fPlays(game);
  o = oPlays(game);

  for(i=1; i<f->lenght; i++) {
    list_node_p newSucessor = createVertice(graph, node);

    newSucessor->father = node;

    copyBoard(newSucessor->game, game);

    readMove(newSucessor->game, f->type, f->plays[i]);

    addEdge(graph, node, newSucessor, i-1);
  }

  for(i=1; i<o->lenght; i++) {
    list_node_p newSucessor = createVertice(graph, node);

    newSucessor->father = node;

    copyBoard(newSucessor->game, game);

    readMove(newSucessor->game, o->type, o->plays[i]);

    addEdge(graph, node, newSucessor, i-1);
  }
}

list_node_p createNode(game_p game, nodeType type) {
  list_node_p node = (list_node_p)malloc(sizeof(list_node_t));
  if(!node)
    err_exit("Unable to create a new Node!");

  if(game) {
    node->game = game;
  } else {
    node->game = (game_p)malloc(sizeof(game_t));
    if(!node->game)
      err_exit("Unable to create a new Node Map!");
  }
  node->type = type;
  node->next = NULL;

  return node;
}

list_node_p createVertice(graph_p graph, list_node_p node) {
  graph->vertices++;

  graph->array = (list_p)realloc(graph->array, (graph->vertices)*sizeof(list_t));
  if(!graph->array)
    err_exit("Unable to realloc the Graph!");

  list_node_p newNode;
  if(node->type == MIN) {
    newNode = createNode(NULL, MAX);
  } else {
    newNode = createNode(NULL, MIN);
  }

  graph->array[graph->vertices-1].head = newNode;
  graph->array[graph->vertices-1].length = 0;

  return graph->array[graph->vertices-1].head;
}

void addEdge(graph_p graph, list_node_p src, list_node_p dest, int index) {

  list_node_p node = createNode(dest->game, dest->type);
  
  list_node_p aux = src;
  
  while(aux->next) {
    aux = aux->next;
  }

  aux->next = node;
  aux->next->vertex = dest;
  aux->next->vertex->father = src;
  aux->next->father = aux;

  graph->array[index].length++;
  
}

graph_p createGraph(int n) {
  int i;

  graph_p graph = (graph_p)malloc(sizeof(graph_t));
  if(!graph)
    err_exit("Unable to create a new Graph!");

  graph->vertices = n;

  graph->array = (list_p)malloc(n*sizeof(list_t));
  if(!graph->array)
    err_exit("Unable to create a new Array!");

  for(i=0; i<n; i++) {
    graph->array[i].head = NULL;
    graph->array[i].length = 0;
  }

  return graph;
}

void destroyGraph(graph_p graph) {
  if(graph) {
    if(graph->array) {
      int v;
    
      for(v=0; v<graph->vertices; v++) {
        list_node_p listPtr = graph->array[v].head;

        while(listPtr) {
          list_node_p tmp = listPtr;
          listPtr = listPtr->next;
          free(tmp);
        }

      }

      free(graph->array);
    }

    free(graph);
  } else {
    err_exit("The Graph is empty!");
  }

}

void printGraph(graph_p graph) {
  if(!graph)
    err_exit("The Graph is empty!");

  int i;

  for(i=0; i<graph->vertices; i++) {
    list_node_p listPtr = graph->array[i].head;
    printf("\nVertice %d: head->", i);
  
    while(listPtr) {
      //showcolorMap(listPtr->map);
      listPtr = listPtr->next;
      printf("->");
    }
    
    printf("NULL\n");
  }
}
