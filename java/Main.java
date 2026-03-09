
public class Main {
    public static void main(String[] args) {
        // 1. Creating a student with valid data (Constructor)
        Student s1 = new Student("Ahmed Ali", 20, 85.5);
        // 2. Attempting to input invalid data (Encapsulation / Setters)
        System.out.println("--- Attempting to modify data with invalid values ---");
        s1.setAge(2);
        // Age is too young (should be rejected)
        s1.setGrade(150);
        // Grade is over 100 (should be rejected)
        // 3. Displaying final data (Methods / Getters)
        System.out.println("\n--- Final Student Report ---");
        s1.printReport();
    }
}



class Student {
    String name;
    int age;
    double grade;
    public Student(String name_ , int age_ , double grade_) {
        name = name_;
        age = age_;
        grade = grade_;
    }
    public void setAge(int age_) {
        if(age_ < 5) {
            System.out.println("Error: Age must be greater than 5 years!");
        } else {
            age  = age_;
        }
    }
    public void setGrade(double grade_) {
        if(grade_ > 100 || grade_ < 0) {
            System.out.println("Error: Grade must be between 0 and 100!");
        } else {
            grade = grade_;
        }
    }

    public int getAge() {
        return age;
    }
    public double getGrade() {
        return grade;
    }

    public String getName() {
        return name;
    }
    public void printReport() {
        System.out.println("Student name : " + getName());
        System.out.println("Student Age : " + getAge());
        System.out.println("Student Grade : " + getGrade());
    }

}