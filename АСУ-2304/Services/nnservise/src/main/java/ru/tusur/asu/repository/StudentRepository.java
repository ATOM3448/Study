package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Student;

public interface StudentRepository extends JpaRepository<Student, Integer> {
}
