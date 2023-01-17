#include <stdio.h>
#include <limits.h>
#include <string.h>
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
pnode findNode(int name, pnode head)
{
    pnode p = head;
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
    // p->pi = NULL;
    return p;
}
////////////////////////// cmd functions //////////////////////////
// A: build graph
void build_graph_cmd(pnode *head)
{
    int n = 0;
    scanf("%d", &n);
    pnode p = newNode(0, NULL);
    *head = p;
    for (int i = 1; i < n; i++)
    {
        pnode q = newNode(i, NULL);
        p->next = q;
        p = q;
    }
    char cmd_ch;
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
    scanf(" %d", &node_num);                      // get the node number to create / change
    pnode start_node = findNode(node_num, *head); // find node number n
    if (start_node == NULL)                       // create new node - if exist remove edges
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
        pnode dest_node = findNode(i, *head);
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
}
// print graph for self debug
void printGraph_cmd(pnode head)
{
    printf("--------------------!graph!--------------------\n");
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
    pnode p = findNode(node_n, *head);
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
/*

*/
void relax(pedge e, pnode strt) // strt -----e-----> e->endpoint
{                               // check if e->endpoint < weight + strt
    if (strt->curr_sp == INT_MAX)
    {
        return;
    }
    if (e->endpoint->curr_sp > strt->curr_sp + e->weight)
    {
        e->endpoint->curr_sp = strt->curr_sp + e->weight;
    }
}
// ----------------------- belman ford algo ------------------------
int Bellman_Ford(pnode head, int strt, int end)
{
    pnode e = head;
    while (e != NULL) // reseting all nodes to INT_MAX
    {
        e->curr_sp = INT_MAX;
        e = e->next;
    }
    pnode p = findNode(strt, head);
    p->curr_sp = 0;
    e = head;
    while (e->next != NULL) // run |E|-1 TIMES
    {
        pnode temp_head = head;
        while (temp_head != NULL) // run on all edges, and relax them
        {
            pedge edge2relax = temp_head->edges;
            while (edge2relax != NULL)
            {
                relax(edge2relax, temp_head);
                edge2relax = edge2relax->next;
            }
            temp_head = temp_head->next;
        }
        e = e->next;
    }
    // printf("got here, %d\n", INT_MAX);
    pnode jnode = findNode(end, head); // checking the end node shortest path from start
    if (jnode->curr_sp < 0 || jnode->curr_sp == INT_MAX)
    {
        return -1;
    }
    return jnode->curr_sp;
}

// S: shortest path from given i to j
void shortsPath_cmd(pnode head)
{
    int i, j;
    if (scanf(" %d", &i) != 1)
    {
        return;
    }
    if (scanf(" %d", &j) != 1)
    {
        return;
    }
    printf("Dijsktra shortest path %d \n", Bellman_Ford(head, i, j));
}

// T: TSP algo on all graph
// int calc_path(pnode head, int *arr)
// {
//     if (arr == NULL)
//     {
//         return -1;
//     }
//     // if (*(arr + 1) == NULL)
//     // {
//     //     return 0;
//     // }
//     // while (*arr)
//     // {
//     //     /* code */
//     // }
//     return -1;
// }
int calc_path(pnode head, int *num, int n)
{
    int i;
    int path = 0, temp_path;
    for (i = 0; i < n - 1; i++)
    {
        // printf("%d ", num[i]);
        temp_path = Bellman_Ford(head, num[i], num[i + 1]);
        if (temp_path < 0)
        {
            return INT_MAX;
        }
        path += temp_path;
    }
    // printf("\n");
    return path;
}
int calc_permutaions_min(pnode head, int *arr, int size)
{
    int temp, temp_min;
    int i, j;
    int min = INT_MAX;
    for (j = 1; j <= size; j++)
    {
        for (i = 0; i < size - 1; i++)
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            temp_min = calc_path(head, arr, size);
            if (temp_min < min)
            {
                min = temp_min;
            }
        }
    }
    return min;
}
void TSP_cmd(pnode head)
{
    int k, j; // how many nodes to save
    if (scanf(" %d", &k) != 1)
    {
        return;
    }
    int *arr = (int *)malloc(sizeof(int) * k);
    for (size_t i = 0; i < k; i++)
    {
        scanf(" %d", &j);
        *(arr + i) = j;
    }
    int minpath = calc_permutaions_min(head, arr, k); // for every permutaion of arr, calculate the path
    if (minpath == INT_MAX)
    {
        minpath = -1;
    }
    free(arr);
    printf("TSP shortest path: %d \n", minpath);
}