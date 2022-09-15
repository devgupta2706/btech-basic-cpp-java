import java.util.Scanner;

class Stack {
    int top;
    int stack_arr[];
    int size;

    public Stack(int max_size) {
        this.top = -1;
        stack_arr = new int[max_size];
        this.size = max_size;
    }

    void pop() {
        if (top >= 0) {
            System.out.println("Element popped Successfully");
            top--;
        } else {
            System.out.println("No element in the stack to pop\n");
        }
    }

    void push(int element) {
        if (top == size - 1) {
            System.out.println("Stack is Full");
        } else {
            top++;
            stack_arr[top] = element;
        }
    }
}

class MainStack {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Stack S = new Stack(5);
        int element;
        char ch;
        do {
            System.out.println("Enter 1) Push or 2) pop ");
            ch = scn.next().charAt(0);
            if (ch == '1') {
                System.out.println("Enter Element to Push ");
                element = scn.nextInt();
                S.push(element);
            } else if (ch == '2') {
                S.pop();
            }
            System.out.println("Do you want to continue (y or n)");
            ch = scn.next().charAt(0);
        } while ((ch == 'Y' || ch == 'y'));
        scn.close();
    }
}