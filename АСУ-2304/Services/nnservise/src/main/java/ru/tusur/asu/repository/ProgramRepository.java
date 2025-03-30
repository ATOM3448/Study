package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Program;

public interface ProgramRepository extends JpaRepository<Program, Integer> {
}
