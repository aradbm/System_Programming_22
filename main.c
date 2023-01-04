#include <stdio.h>
#include "graph.h"

int main()
{
    // int i = 0, j = 0;
    // scanf("%d%d", &i, &j);
    char cmd_ch = 'D';
    pnode *head = NULL;
    cmd_ch = getchar();
    while (cmd_ch != 'D')
    {
        switch (cmd_ch)
        {
        case 'A':
            head = NULL;
            build_graph_cmd(head);
            break;
        case 'B':
            insert_node_cmd(head);
            break;
        case 'D':
            delete_node_cmd(head);
            break;
        case 'S':
            shortsPath_cmd(head);
            break;
        case 'T':
            TSP_cmd(head);
            break;
        case 'Q':
            goto exit_loop;
        }
        cmd_ch = getchar();
    }
exit_loop:;
    return 0;
}