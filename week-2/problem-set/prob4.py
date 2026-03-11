"""Prob4 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses Call, CallCenter, CustomerOrder, OrderQueue, and related helpers to illustrate the main idea with a small runnable example.
"""

import heapq

class Call:
    """Store one caller together with its priority."""
    def __init__(self, priority, caller):
        """Run the   init   step used in this example.

        Args:
            priority (int): The priority input used by this function.
            caller (str): The caller input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.priority = priority
        self.caller = caller
    
    def __lt__(self, other):
        """Run the   lt   step used in this example.

        Args:
            other (object): The other input used by this function.

        Returns:
            bool: True when the required condition is satisfied, otherwise False.
        """
        return self.priority < other.priority

class CallCenter:
    """Priority queue model for a call centre."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.calls = []
    
    def add_call(self, priority, caller):
        """Insert a new call into the priority queue.

        Args:
            priority (int): The priority input used by this function.
            caller (str): The caller input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        heapq.heappush(self.calls, Call(priority, caller))
    
    def answer_call(self):
        """Remove and return the next caller to answer.

        Returns:
            object: The value produced by this function.
        """
        if self.calls:
            return heapq.heappop(self.calls).caller
        else:
            return None

class CustomerOrder:
    """Store one customer order."""
    def __init__(self, order_number, customer):
        """Run the   init   step used in this example.

        Args:
            order_number (object): The order_number input used by this function.
            customer (str): The customer input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.order_number = order_number
        self.customer = customer

class OrderQueue:
    """First-in, first-out queue for customer orders."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.orders = []
    
    def add_order(self, order_number, customer):
        """Add a customer order to the back of the queue.

        Args:
            order_number (object): The order_number input used by this function.
            customer (str): The customer input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.orders.append(CustomerOrder(order_number, customer))
    
    def send_order(self):
        """Send the next order in first-in, first-out order.

        Returns:
            object: The value produced by this function.
        """
        if self.orders:
            return self.orders.pop(0).customer
        else:
            return None

class Calculator:
    """Postfix-expression calculator built on a stack."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.stack = []
    
    def calculate(self, expression):
        """Evaluate a postfix expression using a stack.

        Args:
            expression (str): The expression input used by this function.

        Returns:
            int: The integer result produced by the algorithm.
        """
        stack = []

        for token in expression.split():
            if token.isdigit():
                stack.append(int(token))
            else:
                operand2 = stack.pop()
                operand1 = stack.pop()
                if token == '+':
                    stack.append(operand1 + operand2)
                elif token == '-':
                    stack.append(operand1 - operand2)
                elif token == '*':
                    stack.append(operand1 * operand2)
                elif token == '/':
                    stack.append(int(operand1 / operand2))
                else:
                    raise ValueError('Invalid operator')

        if len(stack) != 1:
            raise ValueError('Invalid expression')

        return stack.pop()



# Create a CallCenter object
cc = CallCenter()

# Add some calls to the queue with different priorities
cc.add_call(3, "John")
cc.add_call(1, "Jane")
cc.add_call(2, "Jim")

# Answer the highest priority call
print(cc.answer_call())  # "Jane"
print(cc.answer_call())  # "Jim"
print(cc.answer_call())  # "John"
print(cc.answer_call())  # None (no more calls in queue)

# Create an OrderQueue object
oq = OrderQueue()

# Add some orders to the queue
oq.add_order(1, "John")
oq.add_order(2, "Jane")
oq.add_order(3, "Jim")

# Send the next order in the queue
print(oq.send_order())  # "John"
print(oq.send_order())  # "Jane"
print(oq.send_order())  # "Jim"
print(oq.send_order())  # None (no more orders in queue)

# Create a Calculator object
calc = Calculator()

result = calc.calculate('5 1 2 + 4 * + 3 -') # Evaluates to 14
"""
In this example, we evaluate the expression "5 1 2 + 4 * + 3 -", 
which represents the infix expression "(5 + (1 + 2) * 4) - 3". 
The result should be 14, and this is what is printed to the console.
"""
print(result)

