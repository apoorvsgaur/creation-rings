from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
import time

def olx(Job_Post):
    driver = webdriver.Firefox()
    #logging in
    driver.get("https://ssl.olx.in/account/")
    element = driver.find_element_by_name("login[email]")
    element.send_keys(Job_Post.login_id)
    element = driver.find_element_by_name("login[password]")
    element.send_keys(Job_Post.password)
    driver.find_element_by_id("se_userLogin").click()
    time.sleep(5)
    #navigating to the post_job
    driver.get("http://olx.in/posting/?fillBaseCategory=56")
    #filling the 'type-of-ad' drop-down menu
    driver.execute_script("document.getElementById('id-offer-seek').style.display='block';")
    select_box = Select(driver.find_element_by_id("id-offer-seek"))
    time.sleep(2)
    select_box.select_by_value("offer")
    time.sleep(2)
    #filling the 'salary' drop-down menu
    driver.execute_script("document.getElementById('param9').style.display='block';")
    select_box = Select(driver.find_element_by_name("data[param_salary_period]"))
    time.sleep(2)
    select_box.select_by_value("yearly")
    #filling out the salary parameters
    element = driver.find_element_by_name("data[param_salary][from]")
    element.send_keys(Job_Post.min_salary)
    element = driver.find_element_by_name("data[param_salary][to]")
    element.send_keys(Job_Post.max_salary)
    #filling the 'position' drop-down menu
    driver.execute_script("document.getElementById('param13').style.display='block';")
    select_box = Select(driver.find_element_by_name("data[param_job_type]"))
    time.sleep(2)
    select_box.select_by_value("fulltime")
    element = driver.find_element_by_name("data[title]")
    element.send_keys("Looking for a "+ Job_Post.job_title)
    element = driver.find_element_by_name("data[description]")
    element.send_keys(Job_Post.job_description.decode('utf-8'))
    element = driver.find_element_by_id("add-person")
    element.send_keys(Job_Post.name)
    #element = driver.find_element_by_id("add-email")
    #element.send_keys("apoorv@venturesity.com")
    element = driver.find_element_by_id("add-phone")
    element.send_keys(Job_Post.mobile_no)
    element = driver.find_element_by_id("mapAddress")
    element.send_keys(Job_Post.city)
    time.sleep(2)
    element.send_keys(Keys.ARROW_DOWN)
    while(True):
      try:
        driver.find_element_by_id("autosuggest-geo-ul").click()
        break
      except:
        pass
    #time.sleep(2)
    #element.send_keys(Keys.RETURN)
    #time.sleep(2)
    time.sleep(2)
    driver.find_element_by_id("save").click()
    #driver.close()
