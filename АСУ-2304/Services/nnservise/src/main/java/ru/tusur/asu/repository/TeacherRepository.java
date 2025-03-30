package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Teacher;

public interface TeacherRepository extends JpaRepository<Teacher, Integer> {
}
