from hirist import hirist_post
from hasco import hasjob_co
from trovit import trovit

class Job_Data:
    def __init__(self):
       self.login_id = raw_input("Login Email: ")
       self.password = raw_input("Password: ")
       self.job_title = raw_input("Job Title: ")
       self.job_description = raw_input("")
       self.no_of_vacancies = raw_input("No. of vacancies: ")
       self.company_name = raw_input("Company Name: ")
       self.company_website = raw_input("Company Website: ")
       self.city = raw_input("City: ")
       self.min_years = raw_input("Min Years of Experience: ")
       self.max_years = raw_input("Max Years of Experience: ")
       self.category_1 = raw_input("Category: (Choose one)\n1.	Programming\n2.	Interaction Design\n3. Graphic Design\n4. Testing\n5. Systems Administration\n6. Business/Management\n7. Writer/Editor\n8. Customer Support\n9.	Mobile (iPhone, Android, other)\n10. Office Administraion\n")
       self.category_2 = raw_input("Category: (Choose one)\n1. Online/Mobile/Web\n2. UI/UX/Product\n3. Systems/Product Software\n4. Semiconductor/VLSI/EDA\n5. Enterprise-SAP/Oracle\n6. Others\n")
       self.min_salary = raw_input("Min Salary (Annually in Rs.)")
       self.max_salary = raw_input("Max Salary (Annually in Rs.)(Less than 4 times Min. Salary)")


Job_Post = Job_Data()
print "Hirist started"
hirist_post(Job_Post)
print "Hirist Done"
print "Hasjob started"
hasjob_co(Job_Post)
print "Hasjob Done"
print "Trovit started"
trovit(Job_Post)
print "Trovit Done"
