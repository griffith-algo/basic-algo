"""Prob2 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses create_adjacency_matrix, create_adjacency_list, is_complete, has_loop, and related helpers to illustrate the main idea with a small runnable example.
"""

def create_adjacency_matrix(num_vertices, edges):
    # Initialize the matrix with zeros
    """Build an adjacency matrix for an undirected graph.

    Args:
        num_vertices (int): The num_vertices input used by this function.
        edges (list): The graph edges used to build the structure.

    Returns:
        list: The list produced by the algorithm.
    """
    matrix = [[0 for j in range(num_vertices)] for i in range(num_vertices)]
    
    # Add the edges to the matrix
    for edge in edges:
        matrix[edge[0]][edge[1]] = 1
        matrix[edge[1]][edge[0]] = 1
    
    return matrix

def create_adjacency_list(num_vertices, edges):
    # Initialize the dictionary with empty lists
    """Build an adjacency list for an undirected graph.

    Args:
        num_vertices (int): The num_vertices input used by this function.
        edges (list): The graph edges used to build the structure.

    Returns:
        dict: The dictionary produced by the algorithm.
    """
    graph = {i: [] for i in range(num_vertices)}
    
    # Add the edges to the dictionary
    for edge in edges:
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])
    
    return graph

def is_complete(matrix_or_list):
    """Check whether the graph contains every possible edge.

    Args:
        matrix_or_list (object): The graph represented as either an adjacency matrix or adjacency list.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    is_complete = True
    
    if type(matrix_or_list) == list:
        # Check if the adjacency matrix is complete
        for i in range(len(matrix_or_list)):
            for j in range(len(matrix_or_list[i])):
                if i != j and matrix_or_list[i][j] == 0:
                    is_complete = False
                    break
    else:
        # Check if the adjacency list is complete
        num_vertices = len(matrix_or_list)
        for i in range(num_vertices):
            if len(matrix_or_list[i]) != num_vertices - 1:
                is_complete = False
                break
    
    return is_complete

def has_loop(matrix_or_list):
    """Check whether the graph contains a self-loop.

    Args:
        matrix_or_list (object): The graph represented as either an adjacency matrix or adjacency list.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    has_loop = False
    
    if type(matrix_or_list) == list:
        # Check if the adjacency matrix has a loop
        for i in range(len(matrix_or_list)):
            if matrix_or_list[i][i] == 1:
                has_loop = True
                break
    else:
        # Check if the adjacency list has a loop
        num_vertices = len(matrix_or_list)
        for i in range(num_vertices):
            if i in matrix_or_list[i]:
                has_loop = True
                break
    
    return has_loop

def has_isolated_vertex(matrix_or_list):
    """Check whether the graph contains a vertex with no neighbours.

    Args:
        matrix_or_list (object): The graph represented as either an adjacency matrix or adjacency list.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    has_isolated_vertex = False
    
    if type(matrix_or_list) == list:
        # Check if the adjacency matrix has an isolated vertex
        for i in range(len(matrix_or_list)):
            is_isolated = True
            for j in range(len(matrix_or_list[i])):
                if matrix_or_list[i][j] == 1:
                    is_isolated = False
                    break
            if is_isolated:
                has_isolated_vertex = True
                break
    else:
        # Check if the adjacency list has an isolated vertex
        num_vertices = len(matrix_or_list)
        for i in range(num_vertices):
            if len(matrix_or_list[i]) == 0:
                has_isolated_vertex = True
                break
    
    return has_isolated_vertex


# Example usage
edges = [(0, 1), (0, 2), (0,3), (1, 2), (1, 3), (2, 3)] # Add (0,0) or (1,1) or (2,2) or (3,3) to get the loop
num_vertices = 4 # Change to 5 to get isolated vertex

# Create the adjacency matrix and adjacency list
matrix = create_adjacency_matrix(num_vertices, edges)
graph = create_adjacency_list(num_vertices, edges)

# Check for the three conditions using the adjacency matrix
print("Adjacency Matrix:")
print("The graph is complete:", is_complete(matrix))
print("The graph has a loop:", has_loop(matrix))
print("The graph has an isolated vertex:", has_isolated_vertex(matrix))