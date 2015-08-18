from flask import Flask, render_template, request
from hirist import hirist_post
from hasco import hasjob_co
from trovit import trovit
from olx import olx
from indeed import indeed
from quickr import quickr

class Job_Data:
    def __init__(self, name, mobile_no, id_1, password, title, desc, vac, comp_name, comp_website, city, miny, maxy, cat1, cat2, cat3, mins, maxs):
     self.name = name
     self.mobile_no = mobile_no
     self.login_id = id_1
     self.password = password
     self.job_title = title
     self.job_description = desc
     self.no_of_vacancies = vac
     self.company_name = comp_name
     self.company_website = comp_website
     self.city = city
     self.min_years = miny
     self.max_years = maxy
     self.category_1 = cat1
     self.category_2 = cat2
     self.category_3 = cat3
     self.min_salary = mins
     self.max_salary = maxs

app = Flask(__name__)
@app.route('/')
@app.route('/index')
def index():
     return render_template('index.html')

@app.route('/', methods=['POST'])
def post_details():
     Job_Post = Job_Data(request.form['name'], request.form['mobile_no'],\
                         request.form['loginid'], request.form['password'], request.form['jobtitle'], request.form['jobdescription'].encode('utf-8'),\
                         request.form['vac'], request.form['comp_name'], request.form['comp_website'], request.form['city'],\
                         request.form['min_years'], request.form['max_years'], request.form['Hasjob Category'], request.form['Hirist Category'],\
                         request.form['Quickr Category'], request.form['min_salary'], request.form['max_salary'])
     check_list = request.form.getlist('check')
     if unicode("OLX") in check_list:
         print "OLX started"
         olx(Job_Post)
         print "OLX done"
     if unicode("Quickr") in check_list:
         print "Quickr started"
         quickr(Job_Post)
         print "Quickr Done"
     if unicode("Indeed") in check_list:
         print "Indeed started"
         indeed(Job_Post)
         print "Indeed done"
     if unicode("Hasjob") in check_list:
         print "Hasjob started"
         hasjob_co(Job_Post)
         print "Hasjob done"
     if unicode("Hirist") in check_list:
         print "Hirist started"
         hirist_post(Job_Post)
         print "Hirist done"
     if unicode("Trovit") in check_list:
         print "Trovit started"
         trovit(Job_Post)
         print "Trovit done"
     return "Done."

    #  print "OLX started"
    #  olx(Job_Post)
    #  print "OLX finished"
    #  print "Indeed started"
    #  indeed(Job_Post)
    #  print "Indeed finished"
    #  print "Quickr started"
    #  quickr(Job_Post)
    #  print "Quickr finished"
    #  print "Hasjob started"
    #  hasjob_co(Job_Post)
    #  print "Hasjob Done"
    #  print "Hirist started"
    #  hirist_post(Job_Post)
    #  print "Hirist Done"
    #  print "Trovit started"
    #  trovit(Job_Post)
    #  print "Trovit Done"



if __name__ == "__main__":
    app.run(debug=True)
