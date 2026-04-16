class Library:
    def __init__(self, name, book, user, author, employee):
        self.name = name
        self.book = book 
        self.user = user 
        self.author = author
        self.employee = employee

    def __str__(self):
        return f"{self.name} {self.book} {self.user} {self.author} {self.employee}"
L1 = Library("Biblioteka Univwersetycka", "Book A", "User X", "Author Y", "Employee Z")
print(L1)