package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Indicator;

public interface IndicatorRepository extends JpaRepository<Indicator, Integer> {
}
