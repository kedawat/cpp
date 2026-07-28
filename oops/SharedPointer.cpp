#include <iostream>
#include <memory>
#include <string>
#include <vector>

class User {
public:
    User(std::string name) : name_(std::move(name)) {
        std::cout << "User created: " << name_ << '\n';
    }

    ~User() {
        std::cout << "User destroyed: " << name_ << '\n';
    }

    void print() const {
        std::cout << "User name: " << name_ << '\n';
    }

private:
    std::string name_;
};

// Function that returns a shared_ptr
std::shared_ptr<User> createUser(const std::string& name) {
    return std::make_shared<User>(name);
}

// Function that takes shared_ptr by value
// Copying into this function increases the reference count
void showUser(std::shared_ptr<User> u) {
    std::cout << "Inside showUser, use_count = " << u.use_count() << '\n';
    u->print();
}

// Function that takes shared_ptr by const reference
// No extra copy, so no reference-count increment for the parameter itself
void observeUser(const std::shared_ptr<User>& u) {
    std::cout << "Inside observeUser, use_count = " << u.use_count() << '\n';
    u->print();
}

// Example of weak_ptr to avoid circular reference
struct Parent;

struct Child {
    std::weak_ptr<Parent> parent;   // non-owning back-reference
};

struct Parent {
    std::shared_ptr<Child> child;    // owning reference
};

int main() {
    // 1) Creation using make_shared
    std::shared_ptr<User> p1 = std::make_shared<User>("Nilesh");
    std::cout << "After creation, p1.use_count = " << p1.use_count() << '\n';

    // 2) Copy shared_ptr: both point to same object, ref count increases
    std::shared_ptr<User> p2 = p1;
    std::cout << "After copy to p2, p1.use_count = " << p1.use_count() << '\n';

    // 3) Access object using ->
    p1->print();

    // 4) Pass by value: count increases inside function call
    showUser(p1);
    std::cout << "After showUser, p1.use_count = " << p1.use_count() << '\n';

    // 5) Pass by const reference: no extra copy of shared_ptr parameter
    observeUser(p1);
    std::cout << "After observeUser, p1.use_count = " << p1.use_count() << '\n';

    // 6) Returned shared_ptr from function
    auto p3 = createUser("Alice");
    std::cout << "p3.use_count = " << p3.use_count() << '\n';

    // 7) Use in a container
    std::vector<std::shared_ptr<User>> users;
    users.push_back(p1);
    users.push_back(p3);
    std::cout << "After storing in vector, p1.use_count = " << p1.use_count() << '\n';

    // 8) weak_ptr example to break cycle
    auto parent = std::make_shared<Parent>();
    auto child = std::make_shared<Child>();

    parent->child = child;   // Parent owns Child
    child->parent = parent;  // Child only observes Parent

    std::cout << "parent.use_count = " << parent.use_count() << '\n';
    std::cout << "child.use_count = " << child.use_count() << '\n';

    // 9) Safely access weak_ptr using lock()
    if (auto lockedParent = child->parent.lock()) {
        std::cout << "Parent is still alive\n";
    } else {
        std::cout << "Parent expired\n";
    }

    return 0;
}