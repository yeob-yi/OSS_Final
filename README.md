# Class register priority calculator
Hello my name is 22100014 Shinyeob Kang.

I made class register priority calculator as my OSS Final Project.

## What does this project do? and Why is this project useful?
My class register priority calculator calculates the priority of class registration.

There are already many services which help you to make timetable. For example, you can make your timetable with Everytime, the well-known app for college student.

In fact, no matter how well you schedule, it's no use if you failing to register for the course. So I think the order of applying classes is much important.

And there are no service which calculates the priority of class registration. The day before the class registration, I had to check hisnet how many students had prospective register to the classes.

So I made this program, to caculate the priority conveniently.

## How to get started?
### 1. Clone my project to your raspberry pi.
### 2. Set the raspberry pi.
#### 2-1. Check the version of chromium on your raspberry pi
#### 2-2. Download the proper version of chromium driver on http://ports.ubuntu.com/pool/universe/c/chromium-browser/
#### 2-3. depackage the chromium driver with following command:
sudo dpkg -i chromium-chromedriver_65.0.3325.181-0ubuntu0.14.04.1_armhf.deb
#### 2-4. Install python packages with following commands:
pip3 install selenium

pip3 install pyperclip
### 3. Compile and run get_user_info.c and give your timetable information
### 4. Run python file with following commands:
python3 get_subject_info.py
### 5. Compile and run calculator.c
Then you will get the results of calculation

## Where can people get more help?
Please refer to this website when you have trouble while installing chromium driver. https://m.blog.naver.com/dsz08082/221877958842

If you need more help, mail me yeob@handong.ac.kr

## Presentation video
https://www.youtube.com/watch?v=4CY0wOdRU7k
