package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Faculty;

public interface FacultyRepository extends JpaRepository<Faculty, Integer> {
}
