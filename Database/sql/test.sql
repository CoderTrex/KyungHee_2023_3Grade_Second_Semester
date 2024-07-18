-- 1번
-- select first_name, salary
-- from HR.employees
-- where salary > 12000;

-- 2번
-- select first_name, department_id
-- from HR.employees
-- where department_id = 176;

-- 3번
-- select first_name, salary
-- from HR.employees
-- where (salary < 5000 or 12000 < salary)

-- 4번
-- select first_name, salary
-- from HR.employees
-- where (salary >= 5000 and 12000 >= salary) and (department_id = 20 or department_id = 50)
-- order by salary

-- 5번
-- select first_name, department_id
-- where department_id = 20 or department_id = 50
-- order by first_name

-- 6번
-- select first_name as "Employee", salary as "Monthly Salary"
-- from HR.employees
-- where (salary >= 5000 and salary <= 12000) and (department_id = 50 or department_id = 20);

-- 7번
-- select first_name, job_id
-- from HR.employees
-- where manager_id is NULL;

-- 8번
-- SELECT first_name, salary, commission_pct
-- FROM HR.employees
-- WHERE commission_pct IS NOT NULL
-- ORDER BY salary DESC, commission_pct DESC;

-- 9번
-- select first_name
-- from HR.employees
-- where first_name like '__a%';

-- 10번
-- select first_name
-- from HR.employees
-- where first_name like '%a%' and first_name like '%e%';

-- 11번
-- select e.first_name, j.job_title, e.salary
-- from HR.employees e
-- join HR.jobs j on e.job_id = j.job_id
-- where (j.job_id = 'SA_REP' or j.job_id = 'ST_CLERK') and e.salary not in (2500, 3500, 7000);

-- 12번
-- select first_name, salary, commission_pct
-- from HR.employees
-- where commission_pct = 0.2