import java.util.Scanner;

class Queue {
    int size, count;
    Node N, Front, End;

    public Queue(int size) {
        this.size = size;
        this.count = 0;
    }

    void push(int element) {
        if (count == 0) {
            Front = new Node(element);
            End = Front;
            this.count++;
        } else if (count < this.size) {
            End.next = new Node(element);
            End = End.next;
            this.count++;
        } else {
            System.out.println("Queue is Full");
        }
    }

    void pop() {
        if (this.count == 0) {
            System.out.println("No element in the Queue to pop\n");
            return;
        }
        this.Front = this.Front.next;
        this.count--;
        System.out.println("Element popped Successfully");
    }
}

class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
    }
}

class MainQueue {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Queue Q = new Queue(5);
        int element;
        char ch;
        do {
            System.out.println("Enter 1) Push or 2) pop ");
            ch = scn.next().charAt(0);
            if (ch == '1') {
                System.out.println("Enter Element to Push ");
                element = scn.nextInt();
                Q.push(element);
            } else if (ch == '2') {
                Q.pop();
            }
            System.out.println("Do you want to continue (y or n)");
            ch = scn.next().charAt(0);
        } while ((ch == 'Y' || ch == 'y'));
        scn.close();
    }
}