package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Result;

public interface ResultRepository extends JpaRepository<Result, Integer> {
}
