#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
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
pnode newNode(int name, pnode next)
{
    pnode p = (pnode)malloc(sizeof(node));
    p->node_num = name;
    p->next = next;
    p->edges = NULL;
    return p;
}
// A: build graph
void build_graph_cmd(pnode *head)
{
    int n = 0;
    printf("Enter number of nodes: \n");
    scanf("%d", &n);
    printf("got n = %d\n", n);
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
    printf("Enter n to insert data: \n");
    scanf(" %c", &cmd_ch);
    printGraph_cmd(*head);
    while (cmd_ch == 'n')
    {
        insert_node_cmd(head);
    }
    printGraph_cmd(*head);
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

// B: insert node
void insert_node_cmd(pnode *head)
{
    int node_num = 0;
    printf("node number to add data\n");
    scanf("%d", &node_num); // get the node number to create / change
    // find node number n
    pnode start_node = findNode(node_num, head);
    // check if n already exist, if yes - free his edges
    if (start_node != NULL)
    {
        free(start_node->edges);
        printf("printing graph \n");
        printGraph_cmd(*head);
    }

    int i, weight; // i is destinaion, j is weight
    printf("enter couple of numbers: dest, weight\n");
    int check_scan = 0;
    while ((check_scan = scanf("%d%d", &i, &weight)))
    {
        if (check_scan != 2)
        {
            break;
        }
        // create a edge from n to i with i as weight
        pnode dest_node = findNode(i, head);
        add_edge_to_node(weight, start_node, dest_node);
        printGraph_cmd(*head);
    }
    printf("Finished addind data to graph of node %d. continue:\n", node_num);
}
////////////////////////// cmd functions //////////////////////////
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
void delete_node_cmd(pnode *head)
{
}
void shortsPath_cmd(pnode head)
{
}
void TSP_cmd(pnode head)
{
}
