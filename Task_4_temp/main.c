#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char cmd_ch;
    pnode *head;

    while ((cmd_ch = getchar()) != EOF)
    {
        switch (cmd_ch)
        {
        case 'A':
            // printf("A\n");
            deleteGraph_cmd(*head);
            build_graph_cmd(*head);
            break;
        case 'B':
            insert_node_cmd(*head);
            break;
        case 'D':
            delete_node_cmd(*head);
            break;
        case 'S':
            shortsPath_cmd(head);
            break;
        case 'T':
            TSP_cmd(head);
            break;
        }
        printGraph_cmd(head);
        cmd_ch = getchar();
    }
    return 0;
}
pedge create_new_edge(int weight, pnode dest_node)
{
    pedge p;
    p->endpoint = dest_node;
    p->weight = weight;
    p->next = NULL;
    return p;
}
void add_edge_to_node(int weight, pnode start_node, pnode dest_node)
{
    pedge p = start_node->edges;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = create_new_edge(weight, dest_node);
}
pnode newNode(int name, pnode next)
{
    pnode p;
    p->node_num = name;
    p->next = next;
    p->edges = NULL;
    return p;
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
// print graph
void printGraph_cmd(pnode head)
{
    pnode p = head;
    while (p != NULL)
    {
        printf("%d", p->node_num);
        pedge e = p->edges;
        while (e != NULL)
        {
            printf("->%d(%d)", e->endpoint->node_num, e->weight);
            e = e->next;
        }
        printf("\n");
        p = p->next;
    }
}
// A: build graph
void build_graph_cmd(pnode *head)
{
    int n = 0;
    scanf("%d", &n);
    // for to create n nodes
    for (int i = 0; i < n; i++)
    {
        pnode p = newNode(i, NULL);
        p->next = *head;
        *head = p;
    }
    char cmd_ch = getchar(); // if n than start insert node
    while (cmd_ch == 'n')
    {
        insert_node_cmd(head);
    }
}
// B: insert node
void insert_node_cmd(pnode *head)
{
    int node_num = 0;
    scanf("%d", &node_num); // get the node number to create / change
    // find node number n
    pnode start_node = findNode(node_num, head);
    // check if n already exist, free his edges

    int i, weight; // i is destinaion, j is weight
    while (scanf("%d%d", &i, &weight) == 2)
    {
        // create a edge from n to i with i as weight
        pnode dest_node = findNode(i, head);
        add_edge_to_node(weight, start_node, dest_node);
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