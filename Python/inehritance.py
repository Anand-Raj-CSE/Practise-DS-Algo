from os import name


class parent:
    def __init__(self,name,empid):
        self.name = name
        self.empid = empid
    
    def show(self):
        print("Name of the emplyee is {} having employee id".format(self.name,self.empid))

class child(parent):
    def __init__(self, name, empid,status,domain):
        super().__init__(name, empid)
        self.status = status
        self.domain = domain

    def display(self):
        print("Satus of employee is : {} and the domain is {}".format(self.status,self.domain))
        print("Above domain and status is of emplyee {} having employee id is {} ".format(self.name,self.empid))



chldobj = child("ANUJ",12356,"Intern","FTE")
chldobj.display()
chldobj.show()