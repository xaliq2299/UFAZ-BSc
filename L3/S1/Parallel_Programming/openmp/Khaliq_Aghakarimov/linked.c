#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#define NODES 5

struct list {
  int value;
  struct list* next;
};

/* ------------------------------------------------------------------------ *
 *      UTILITY FUNCTIONS NOT USEFUL FOR YOUR PURPOSE - DO NOT TOUCH        *
 * ------------------------------------------------------------------------ */

// Return a pointer to a newly allocated list structure
// with the "value" field initialized with the "value" parameter
// and the "next" field initialized to NULL.
struct list* list_new(int value) {
  struct list* new = malloc(sizeof(struct list));
  new->value = value;
  new->next = NULL;
  return new;
}

// Free the memory allocated for the whole list.
void list_free(struct list* list) {
  struct list* next;
  while (list != NULL) {
    next = list->next;
    free(list);
    list = next;
  }
}

// Pretty-print the list.
void list_print(struct list* list) {
  int i = 1;
  printf("List:\n");
  while (list != NULL) {
    if (list->value != 0)
      printf("Node %d: job (duration: %d s)\n", i, list->value);
    else
      printf("Node %d: no job\n", i);
    list = list->next;
    i++;
  }
}

// Returns a pointer to a list of "nb_nodes" newly allocated
// list nodes with the "value" field of the n^th node set to n.
struct list* list_init(int nb_nodes) {
  struct list* list, *current;
  int i;

  if (nb_nodes > 0) {
    list = current = list_new(1);
    for (i = 1; i < nb_nodes; i++) {
      current->next = list_new(i+1);
      current = current->next;
    }
  }
  return list;
}

// Simulation of a processing on one list node (the calling
// thread will simply sleep "value" seconds and increment it).
void list_process_node(struct list* node) {
  if (node != NULL) {
    if (node->value == 0) {
      printf("Warning: already processed node!\n");
    }
    sleep(node->value);
    node->value = 0;
  }
}

/* ------------------------------------------------------------------------ *
 *       FUNCTION YOU HAVE TO PARALLELIZE USING OpenMP - DO TOUCH !         *
 * ------------------------------------------------------------------------ */

// Processing of all the list nodes.
void list_process(struct list* list) {
  while (list != NULL) {
    list_process_node(list);
    list = list->next;
  }
}

/* ------------------------------------------------------------------------ *
 *                      MAIN FUNCTION - DO NOT TOUCH                        *
 * ------------------------------------------------------------------------ */

int main() {
  struct list* list = list_init(NODES);
  list_print(list);
  double time = omp_get_wtime();
  printf("Processing the list...\n");
  list_process(list);
  time = omp_get_wtime() - time;
  list_print(list);
  list_free(list);
  printf("Processing time : %3.5lf s\n", time);
  return 0;
}