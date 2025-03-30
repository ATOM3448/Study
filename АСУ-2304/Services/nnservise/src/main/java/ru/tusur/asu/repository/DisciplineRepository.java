package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Discipline;

public interface DisciplineRepository extends JpaRepository<Discipline, Integer> {
}
