#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 5
#define  maxVal 9999
int jarakMin(int jarak[V], bool dikunjungi[V])
{
    int min = maxVal;
    int min_index = -1;
    for(int x = 0; x < V; x++)
    {
        if(dikunjungi[x] == false && jarak[x] <= min)
        {
            min = jarak[x];
            min_index = x;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int start)
{
    int jarak[V];
    bool dikunjungi[V];
    int kotaKeberangkatan[V];

    for(int i = 0; i < V; i++)
    {
        jarak[i] = maxVal;
        dikunjungi[i] = false;
        kotaKeberangkatan[i] = start;
    }

    jarak[start] = 0;

    for(int x = 0; x < V - 1; x++)
    {
        int index = jarakMin(jarak, dikunjungi);

        dikunjungi[index] = true;

        for(int v = 0; v < V; v++)
        {
            if(dikunjungi[v] == false && graph[index][v] != 0 && jarak[index] != maxVal && jarak[index] + graph[index][v] < jarak[v]){
                jarak[v] = jarak[index] + graph[index][v];
                kotaKeberangkatan[v] = index;
            }
        }
    }
    printf("Node\tJarak dari node %d\t\tKota keberangkatan\n", start);
    for(int v = 0; v < V; v++)
    {
        printf("%d\t\t %d\t\t\t\t\t%d\n", v, jarak[v], kotaKeberangkatan[v]);
    }
}


int main()
{
    printf("Welcome to Simple Maps\n");
    printf("Would you like to create your own map or use one of our presets?\n>> Use my own (1) / Use a preset (2)\n>> ");
    int type;
    scanf("%d", &type);
    if(type == 2)
    {
        printf("Here are some map presets available, pick them by the preset number.\n");
        printf("Preset 1\n");
        printf("                    (1) -1- (2)\n");
        printf("                   /  \\      /\n");
        printf("                  3    4    2\n");
        printf("                 /      \\  /\n");
        printf("              (0) --7--  (3)\n");
        printf("               \\         /\n");
        printf("                12      3\n");
        printf("                 \\    /\n");
        printf("                   (4)\n");
        printf("Preset 2\n");
        printf("            (0) --4-- (1)\n");
        printf("            |        /   \\\n");
        printf("            |       /     3\n");
        printf("            |      /       \\\n");
        printf("            2     5       (2)\n");
        printf("            |    /        /\n");
        printf("            |   /        3\n");
        printf("            |  /        /\n");
        printf("            (4) --3-- (3)\n");
        printf(">> ");
        int preset;
        scanf("%d", &preset);
        int graph1[V][V] = {{0, 3, 0, 7, 12},
                            {3, 0, 1, 4, 0},
                            {0, 1, 0, 2, 0},
                            {7, 4, 2, 0, 3},
                            {12, 0, 0, 3, 0}};

        int graph2[V][V] = {{0, 4, 0, 0, 2},
                            {4, 0, 3, 0, 5},
                            {0, 3, 0, 3, 0},
                            {0, 0, 3, 0, 3},
                            {2, 5, 0, 3, 0}};

        if(preset == 1)
        {
            printf("Map:\n");
             printf("Here are some map presets available, pick them by the preset number.\n");
        printf("Preset 1\n");
        printf("                    (1) -1- (2)\n");
        printf("                   /  \\      /\n");
        printf("                  3    4    2\n");
        printf("                 /      \\  /\n");
        printf("          You->(0) --7--  (3)\n");
        printf("               \\         /\n");
        printf("                12      3\n");
        printf("                 \\    /\n");
        printf("                   (4)\n");

        }

        dijkstra(graph1, 0);



    }
}
