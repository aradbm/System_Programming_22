// To Do:
// create freeEdges method
// algorithm functions
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
/////////////////// edge&node handling functions //////////////////
pedge create_new_edge(int weight, pnode dest_node)
{
    pedge p = (pedge)malloc(sizeof(edge));
    p->endpoint = dest_node;
    p->weight = weight;
    p->next = NULL;
    return p;
}
void add_edge_to_node(int weight, pnode start_node, pnode dest_node)
{
    pedge p = create_new_edge(weight, dest_node);
    pedge e = start_node->edges;
    if (e == NULL)
    {
        start_node->edges = p;
        return;
    }
    while (e->next != NULL)
    {
        e = e->next;
    }
    e->next = p;
}
pnode findNode(int name, pnode *head)
{
    pnode p = *head;
    while (p != NULL)
    {
        if (p->node_num == name)
            return p;
        p = p->next;
    }
    return NULL;
}
pnode newNode(int name, pnode next)
{
    pnode p = (pnode)malloc(sizeof(node));
    p->node_num = name;
    p->next = next;
    p->edges = NULL;
    return p;
}
////////////////////////// cmd functions //////////////////////////
// A: build graph
void build_graph_cmd(pnode *head)
{
    int n = 0;
    // printf("Enter number of nodes: \n");
    scanf("%d", &n);
    pnode p = newNode(0, NULL);
    *head = p;
    // for to create n nodes
    for (int i = 1; i < n; i++)
    {
        pnode q = newNode(i, NULL);
        p->next = q;
        p = q;
    }
    char cmd_ch; // if n than start insert node
    // printf("Enter 'n' to insert data: \n");
    // runs n times
    for (size_t i = 0; i < n; i++)
    {
        scanf(" %c", &cmd_ch);
        insert_node_cmd(head);
        // printf("%c\n", cmd_ch);
    }
}
// B: insert node
void free_edges(pedge *edges_p)
{
    pedge e = *edges_p;
    while (e != NULL)
    {
        pedge tmp = e;
        e = e->next;
        free(tmp);
    }
    *edges_p = NULL;
}
void insert_node_cmd(pnode *head)
{
    int node_num = 0;
    scanf(" %d", &node_num);                     // get the node number to create / change
    pnode start_node = findNode(node_num, head); // find node number n
    if (start_node == NULL)                      // create new node - if exist remove edges
    {
        start_node = newNode(node_num, NULL);
        pnode p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = start_node;
    }
    else
        start_node->edges = NULL;
    // free_edges((start_node->edges));
    int i, weight; // i is destinaion, j is weight
    // printf("enter couple of numbers: dest, weight\n");
    while (1)
    {
        if (scanf(" %d", &i) != 1)
        {
            break;
        }
        if (scanf(" %d", &weight) != 1)
        {
            break;
        }
        pnode dest_node = findNode(i, head);
        add_edge_to_node(weight, start_node, dest_node);
        // printGraph_cmd(*head);
    }
}

// delete graph
void deleteGraph_cmd(pnode *head)
{
    pnode p = *head;
    while (p != NULL)
    {
        pnode tmp = p;
        p = p->next;
        free(tmp);
    }
    *head = NULL;
}
// print graph for self debug
void printGraph_cmd(pnode head)
{
    pnode p = head;
    while (p != NULL)
    {
        printf("%d", p->node_num);
        pedge e = p->edges;
        while (e != NULL)
        {
            printf("->(n:%d w:%d)", e->endpoint->node_num, e->weight);
            e = e->next;
        }
        printf("\n");
        p = p->next;
    }
}
// D: Delete node
void remove_edge_by_dest(pnode cur_node, int node_n)
{
    if (node_n == cur_node->node_num)
    {
        return;
    }
    pedge q = cur_node->edges;
    pedge temp;
    if (q == NULL)
    {
        return;
    }
    if (q->endpoint->node_num == node_n)
    {
        temp = q;
        cur_node->edges->next = q->next;
        free(temp);
    }
    while (q->next != NULL)
    {
        if (q->next->endpoint->node_num == node_n)
        {
            temp = q->next;
            q->next = q->next->next;
            free(temp);
        }
    }
}
void delete_node_cmd(pnode *head)
{
    int node_n = 6;
    printf("node number to remove from graph: \n");
    // scanf("%d", &node_n);

    // remove all edges to node_num
    pnode p = *head;
    while (p != NULL)
    {
        printf("%d\n", p->node_num);
        remove_edge_by_dest(p, node_n);
        p = p->next;
    }
    printf("got here \n");
    // remove the connection in the linked nodes
    p = *head;
    printGraph_cmd(*head);
    pnode temp;
    while (p->next->node_num != node_n)
    {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    // free node_num
    free(temp);
}
// S: shortest path from given i to j
void shortsPath_cmd(pnode head)
{
}
// T: TSP algo on all graph
void TSP_cmd(pnode head)
{
}