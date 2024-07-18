select d.department_name, e.first_name, j.job_title, e.salary
from HR.employees e, HR.jobs j, HR.departments d
where j.job_id = e.job_id and d.department_id = e.department_id
order by d.department_id, e.salary desc;



select *
from HR.employees s, HR.jobs j
where s.first_name = 'David' and j.job_id = s.job_id


SELECT *
FROM HR.employees e
INNER JOIN HR.jobs j ON e.job_id = j.job_id
WHERE j.job_title = (SELECT job_title FROM HR.employees WHERE first_name = 'David');
