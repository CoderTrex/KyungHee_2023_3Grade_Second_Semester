-- # 1번 문제 #
-- 별칭을 지정할때는 병칭은 컬럼 명 바로 뒤에 별명을 정의하여야 하며, 
-- 컬럼 명과 별명 사이의 키워드 AS는 써도 되고 안 써도 된다.
-- 만약 빈 칸 또는 특수 문자가 있거나 대소문자를 구별한다면, “ ”가 필요하다.
-- 또한 연산은 X를 사용하지 않고 *를 사용하며, 실제 테이블의 열의 명칭과 일치해야한다.

SELECT employee_id, last_name sal x 12 ANNUAL SALARY (X)
SELECT employee_id as "last_name" , salary*12 "ANNUAL SALARY" (O)

FROM HR.employees;

-- # 2번 문제 #
select *
from HR.departments;

-- # 2번 문제 #
select employee_id, first_name, last_name, job_id, hire_date as STARTDATE
from HR.employees;

-- # 4번 문제 #
SELECT first_name || ', ' || job_id  as "Employee and Title"
FROM HR.employees;


-- ###########
-- ###########
-- # 2번 과제 # 
-- ###########
-- ###########

-- # 1번 문제 #
select first_name, salary
FROM HR.employees
where salary > 12000;

-- # 2번 문제 #
select first_name, department_id
from HR.employees
where employee_id = 176;

-- # 3번 문제 #
select first_name, salary 
from HR.employees
where salary <  5000 and 12000 > salary;

-- # 4번 문제 #
SELECT first_name, salary, department_id
FROM HR.employees
WHERE (salary >= 5000 AND salary <= 12000) AND (department_id = 20 OR department_id = 50)
ORDER BY salary;

-- # 5번 문제 #
select first_name, department_id
from HR.employees
where department_id = 20 or department_id = 50
order by first_name;

-- # 6번 문제 #
select first_name as "Employee", salary as "Monthly Salary"
from HR.employees
where (salary >= 5000 and salary <= 12000) and (department_id = 50 or department_id = 20);

-- # 7번 문제 #
select first_name, department_id
from HR.employees
where manager_id is NULL;

-- # 8번 문제 #
SELECT first_name, salary, commission_pct
FROM HR.employees
WHERE commission_pct IS NOT NULL
ORDER BY salary DESC, commission_pct DESC;

-- # 9번 문제 #
select first_name
from HR.employees
where first_name like '__a%';

-- # 10번 문제 #
select first_name
from HR.employees
where first_name like '%a%' and first_name like '%e%';

-- # 11번 문제 #
select e.first_name, j.job_title, e.salary
from HR.employees e
join HR.jobs j on e.job_id = j.job_id
where (j.job_id = 'SA_REP' or j.job_id = 'ST_CLERK') and e.salary not in (2500, 3500, 7000);

-- # 12번 문제 #
select first_name, salary, commission_pct
from HR.employees
where commission_pct = 0.2;