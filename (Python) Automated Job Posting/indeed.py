from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
import time

def indeed(Job_Post):
    driver = webdriver.Firefox()
        #logging in
    driver.get("https://secure.indeed.com/account/login")
    element = driver.find_element_by_id("signin_email")
    element.send_keys(Job_Post.login_id)
    element = driver.find_element_by_id("signin_password")
    element.send_keys(Job_Post.password)
    driver.find_element_by_class_name("input_submit").click()
    time.sleep(5)
    driver.get("https://employers.indeed.com/m#post-job")
    element = driver.find_element_by_id("company")
    element.clear()
    element.send_keys(Job_Post.company_name)
    element = driver.find_element_by_id("title")
    element.send_keys(Job_Post.job_title)
    ## You have to switch to the iframe like so: ##
    driver.switch_to_frame(driver.find_element_by_tag_name("iframe"))
    ## Insert text via xpath ##
    elem = driver.find_element_by_xpath("/html/body")
    elem.send_keys(Job_Post.job_description.decode('utf-8'))
    ## Switch back to the "default content" (that is, out of the iframes) ##
    driver.switch_to_default_content()
    element = driver.find_element_by_id("location")
    element.clear()
    element.send_keys(Job_Post.city)
    try:
       element = driver.find_element_by_id("experienceType[0]")
    except:
       element = driver.find_element_by_id("experienceType")
    element.send_keys("IT Software - Developer")
    try:
        select_box = Select(driver.find_element_by_id("experienceYears[0]"))
    except:
        select_box = Select(driver.find_element_by_id("experienceYears"))
    time.sleep(1)
    if (Job_Post.min_years > 5):
        select_box.select_by_value("5")
    else:
        select_box.select_by_value(Job_Post.min_years)
    driver.find_element_by_id("postFormSubmit").click()
    while(True):
      try:
         driver.find_element_by_id("submit").click()
         break
      except:
         pass

    while(True):
      try:
         driver.find_element_by_class_name("submitter").click()
         break
      except:
         pass

#indeed()
