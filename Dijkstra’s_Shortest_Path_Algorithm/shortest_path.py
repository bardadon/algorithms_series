import numpy as np

# Step #0 - Set Problem - Start at A, Finish at C
graph = {
    'A': {'B': 6, 'D': 1},
    'B': {'A': 6, 'D': 2, 'C': 5, 'E': 2},
    'C': {'B': 5, 'E': 5},
    'D': {'A': 1, 'B': 2, 'E': 1},
    'E': {'B': 2, 'C': 5, 'D': 1}
}

def dijkstra(graph, start_node):

    # Step #1 - Initialize the graph
    visited = []
    unvisited = list(graph.keys())

    # Step #2 - Initialize the shortest distance
    shortest_distance = {}
    for node in unvisited:
        if node != start_node:
            shortest_distance[node] = np.inf
        else:
            shortest_distance[node] = 0
    print(shortest_distance)

    # Step #3 - Find the shortest path
    number_of_nodes = len(unvisited)
    while len(visited) < number_of_nodes:
        
        # Step #3.1 - Find the node with the shortest distance. That's the current node
        min_distance = np.inf
        for node in unvisited:
            if shortest_distance[node] < min_distance:
                min_distance = shortest_distance[node]
                current_node = node

        # Step #3.2 - Add node to the visited list and remove from unvisited.
        print(f"The current node is: {current_node}")
        visited.append(current_node[0])
        unvisited.remove(current_node[0])

        # Step #3.3 - Update distance from starting node, to current node's neighbors
        # 3.3.1 - Get the neighbors of the current node
        neighbors = graph[current_node[0]]
        for neigh in neighbors:
            distance_start_to_current = shortest_distance.get(current_node)
            distance_current_to_neigh = graph.get(current_node).get(neigh)

            distance_start_to_neigh = distance_start_to_current + distance_current_to_neigh
            print(f"\nThe distance from the starting node(A) to the neighbor({neigh}) is: {distance_start_to_neigh}")

            # 3.3.2 - Update the distance to its neighbors
            if distance_start_to_neigh < shortest_distance.get(neigh):
                shortest_distance[neigh] = distance_start_to_neigh
                print(f"Found Shorter Path! Updating Distances: {shortest_distance}")

    return shortest_distance
