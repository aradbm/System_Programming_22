#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
void free_node(pnode node2remove) // deleting edges out of node + node itself
{
    pedge e = node2remove->edges;
    while (e != NULL)
    {
        pedge temp = e;
        e = e->next;
        free(temp);
    }
    free(node2remove);
}
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
    }
}
// B: insert node
void free_edges(pnode node_ed)
{
    pedge e = node_ed->edges;
    while (e != NULL)
    {
        pedge tmp = e;
        e = e->next;
        free(tmp);
    }
    node_ed->edges = NULL;
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
    {
        free_edges(start_node);
        start_node->edges = NULL;
    }
    int i, weight; // i is destinaion, j is weight
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
        free_node(tmp);
    }
    *head = NULL;
}
// print graph for self debug
void printGraph_cmd(pnode head)
{
    printf("--------------------<graph>--------------------\n");
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
    printf("-----------------------------------------------\n");
}
// D: Delete node
void remove_edges_by_dest(pnode *head, int n)
{
    pnode p = *head;
    pedge temp = NULL;
    while (p != NULL) // find edge to node node_n
    {
        pedge e = p->edges; // q is a pointer to a pointer to the first edge in the list
        if (e != NULL)
        {
            if (e->endpoint->node_num == n)
            {
                temp = e;
                p->edges = e->next;
                free(temp);
            }
            else
            {
                while (e->next != NULL)
                {
                    if (e->next->endpoint->node_num == n)
                    {
                        temp = e->next;
                        e->next = e->next->next;
                        free(temp);
                        break;
                    }
                    e = e->next;
                }
            }
        }
        p = p->next;
    }
}
void delete_node_cmd(pnode *head)
{
    int node_n = 0;
    scanf(" %d", &node_n);
    pnode p = findNode(node_n, head);
    remove_edges_by_dest(head, node_n); // removing all the edges with the null endpoint
    p = *head;
    while (p->next->node_num != node_n) // removing the node from the list
    {
        p = p->next;
    }
    pnode temp = p->next;
    p->next = p->next->next;
    free_node(temp);
}
// S: shortest path from given i to j
void shortsPath_cmd(pnode head)
{
}
// T: TSP algo on all graph
void TSP_cmd(pnode head)
{
}