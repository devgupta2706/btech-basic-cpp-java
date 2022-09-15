import java.util.Scanner;
import java.util.UUID;

class Employee extends Achievement {
    String name, department, department_id;
    int day_born, month_born, year_born;// dd/ mm/yyyy
    String address;// address
    int day_join, month_join, year_join;
    int day_retirement, month_retirement, year_retirement;
    char gender;
    UUID employee_id;
    int department_number = 0;

    public Employee() {
        employee_id = UUID.randomUUID();
    }

    public Employee(String name, int day, int month, int year, String address, char gender, String department) {
        this.name = name;
        this.day_born = day;
        this.month_born = month;
        this.year_born = year;
        this.address = address;
        this.gender = gender;
        this.department = department;
    }

    // function to call retirement date function
    void dateOfjoining(int day_join, int month_join, int year_join) {
        this.day_join = day_join;
        this.month_join = month_join;
        this.year_join = year_join;
        retirementDate();
    }

    void retirementDate() {// to calculate date of retirement
        this.day_retirement = this.day_join;
        this.month_retirement = this.month_join;
        this.year_retirement = this.year_join + 35;
    }

    void displayDetails() {// to show details of the employee
        System.out.println("-----------------Display Details--------------------");
        System.out.println("Employee ID :" + this.employee_id);
        System.out.println("Name:" + this.name);
        System.out.println("Date of birth :" + this.day_born + "-" + this.month_born + "-" + this.year_born);

        System.out.println("Gender :" + this.gender);

        System.out.println("Address :" + this.address);
        System.out.println("Date of JOINING :" + this.day_join + "-" + this.month_join + "-" + this.year_join);
        System.out.println("Date of retirement :" + this.day_retirement + "-" + this.month_retirement + "-"
                + this.year_retirement);
        System.out.println("Department number :" + this.department_number);
        System.out.println("Department ID :" + this.department_id);
        super.displayDetails();
    }

    void getdetails() {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter name");
        name = scn.next();
        scn.nextLine();
        System.out.println("Enter Gender");
        gender = scn.next().charAt(0);
        System.out.println("Enter Department");
        department = scn.next();
        scn.nextLine();
        System.out.println("Enter day of birth (DD)");
        day_born = scn.nextInt();
        System.out.println("Enter month of birth (MM)");
        month_born = scn.nextInt();
        System.out.println("Enter year of birth (YYYY)");
        year_born = scn.nextInt();
        System.out.println("Enter Address");
        address = scn.next();
        scn.nextLine();
        System.out.println("Enter day of joining (DD)");
        day_join = scn.nextInt();
        System.out.println("Enter month of joining (MM)");
        month_join = scn.nextInt();
        System.out.println("Enter year of joining (YYYY)");
        year_join = scn.nextInt();
        scn.nextLine();
        retirementDate();
    }

    void department_details() {
        department_id = department.toUpperCase();
        department_number = department_id.length();
    }
}

class Achievement {
    String projectname[], projectlocation[];
    int numberofprojects;

    public Achievement() {
        projectname = new String[5];// maximum 5
        projectlocation = new String[5];// maximum 5
        numberofprojects = 0;
    }

    void getprojectdetails() {
        Scanner scn = new Scanner(System.in);
        for (int i = 0; i < numberofprojects; i++) {
            System.out.println("Enter project name");
            projectname[i] = scn.next();
            scn.nextLine();
            System.out.println("Enter project Location");
            projectlocation[i] = scn.next();
            scn.nextLine();
        }
    }

    void getproject() {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter number of project the employee have done (max 5)");
        numberofprojects = scn.nextInt();
        getprojectdetails();
    }

    void displayDetails() {// to show details of the employee
        System.out.println("-----------------Project Details--------------------");
        for (int i = 0; i < numberofprojects; i++) {
            System.out.println("Project Name :" + this.projectname[i]);
            System.out.println("Project Location :" + this.projectname[i]);
        }
    }
}

class Main {// main class

    public static void main(String[] args) {
        Employee[] Employees;// array of employye class
        Employees = new Employee[20];// allocating 20 objects of class employee
        char ch = 'n';
        int n = 0;
        Scanner scn = new Scanner(System.in);
        do {
            // taking user input for geting details
            // Constructor calling of class employee
            Employees[n] = new Employee();
            // method to calculate date of retirement
            Employees[n].getdetails();
            Employees[n].getproject();
            Employees[n].department_details();
            // Displaying details of the employee with retirement date
            Employees[n].displayDetails();
            System.out.println("Do you want to continue (y or n)");
            ch = scn.next().charAt(0);
            n++;
        } while (n < 10 && (ch == 'Y' || ch == 'y'));
        scn.close();
    }
}
