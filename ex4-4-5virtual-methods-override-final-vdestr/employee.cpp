#include <iostream>

class Employee {
public:
    virtual const std::string &get_fname() const = 0;

    virtual const std::string &get_lname() const = 0;

    virtual short get_old() const = 0;
};

class Lector : public Employee {
    std::string name, last_name;
    short old{};
    int salary{};

public:
    Lector(std::string name, std::string last_name, short old, int salary = 0): name(std::move(name)),
        last_name(std::move(last_name)), old(old), salary(salary) {}

    void set_salary(int s) {
        if (s > 0)
            salary = s;
    }

    int get_salary() const { return salary; }
    const std::string &get_fname() const override { return name; }
    const std::string &get_lname() const override { return last_name; }
    short get_old() const override { return old; }
};

class Laborant : public Employee {
    std::string first_name, last_name;
    short old{0};
    std::string job_title;

public:
    Laborant(std::string name, std::string last_name, short old,
             std::string job_title = ""): first_name(std::move(name)), last_name(std::move(last_name)), old(old),
                                          job_title(std::move(job_title)) {}

    void set_job_title(std::string j_title) { job_title = std::move(j_title); }
    const std::string &get_job_title() const { return job_title; }
    const std::string &get_fname() const override { return first_name; }
    const std::string &get_lname() const override { return last_name; }
    short get_old() const override { return old; }
};

enum { max_persons = 255, size = 3 };

int main() {
    Employee *staff[max_persons] = {
        new Lector("Sergey", "Balakirev", 33, 85000),
        new Laborant("Elena", "Pozdnjakova", 27, "Programmer"),
        new Lector("Olga", "Levkina", 38, 120000)
    };

    for (int i = 0; i < size; i++) {
        std::cout << staff[i]->get_fname() << " ";
    }

    for (int i = 0; i < size; i++) {
        delete staff[i];
        staff[i] = nullptr;
    }
}
