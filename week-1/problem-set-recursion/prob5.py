"""Prob5 example.

This file belongs to the week 1 recursion practice solutions. It uses transfer_books, move_books to illustrate the main idea with a small runnable example.
"""

def transfer_books(n, source, target, helper):
    """This function recursively transfers n books from the source basket to the target basket,.

    Args:
        n (int): The n input used by this function.
        source (object): The source input used by this function.
        target (object): The target input used by this function.
        helper (object): The helper input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if n == 1:
        if (source[-1] == 'Physics' and target[-1] == 'Chemistry'):
            raise ValueError("Invalid move: Physics book can't be on top of Chemistry book")
        if ((source[-1] == 'Physics' or source[-1] == 'Chemistry') and target[-1] == 'Math'):
            raise ValueError("Invalid move: Physics and Chemistry books can't be on top of Maths book")
        print(f"Move {source[-1]} from {source} to {target}")
        target.append(source.pop())
        return
    transfer_books(n-1, source, helper, target)
    print(f"Move {source[-1]} from {source} to {target}")
    target.append(source.pop())
    transfer_books(n-1, helper, target, source)

# Initial baskets
source = ['Physics', 'Chemistry', 'Maths']
target = []
helper = []

# Transfer books from source to target
transfer_books(len(source), source, target, helper)

print(source)
print(target)
print()

# Cleaner code. Mimic Tower of Hanoi
def move_books(num_books, source, target, helper):
    """Print the recursive moves for the simplified book-moving version of the puzzle.

    Args:
        num_books (int): The num_books input used by this function.
        source (object): The source input used by this function.
        target (object): The target input used by this function.
        helper (object): The helper input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if num_books == 1:
        print(f"Move book {books[num_books-1]} from {source} to {target}")
    else:
        move_books(num_books-1, source, helper, target)
        print(f"Move book {books[num_books-1]} from {source} to {target}")
        move_books(num_books-1, helper, target, source)

books = ["Maths", "Chemistry", "Physics"]
num_books = 3
source = "basket 1"
target = "basket 2"
helper = "basket 3"
move_books(num_books, source, target, helper)
