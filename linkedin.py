#!/usr/bin/python3

class Software_Engineer:
    pass

def get_current_weather():
    return ('weather')

def profile():
    Matt = Software_Engineer()

    Matt.full_name = 'Matthew Allen'
    Matt.email = 'allen_matthew@outlook.com'
    Matt.linkedin = 'https://www.linkedin.com/in/itsmatthewallen/'
    Matt.github = 'https://github.com/mdallen5393'

    Matt.technologies = ['Python', 'C', 'HTML', 'CSS', 'JavaScript', 'Bash', 'Bootstrap']
    Matt.description = ['Humorous', 'Teacher', 'Leader', 'Personable', 'Flexible']

    education = {}
    education['Holberton School Tulsa'] = "In Process"
    education['Oklahoma State University'] = "BS Mechanical Engineering"
    education['Tulsa Community College'] = "AS Mathematics/Engineering"
    Matt.education = education

    Matt.hobbies = ['Cooking', 'Pool (the billiards kind)', 'Video Games', 'Coding']

    weather = get_current_weather()

    if weather in ['rainy', 'cold', 'snowy']:
        Matt.mood = 'happy'
    else:
        Matt.mood = 'the big sads'

    print('This code is useless.')

if __name__ == '__main__':
    profile()
