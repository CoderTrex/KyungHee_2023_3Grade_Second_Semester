select d.department_name, e.first_name, j.job_title, e.salary
from HR.employees e, HR.jobs j, HR.departments d
where j.job_id = e.job_id and d.department_id = e.department_id
order by d.department_id, e.salary desc;