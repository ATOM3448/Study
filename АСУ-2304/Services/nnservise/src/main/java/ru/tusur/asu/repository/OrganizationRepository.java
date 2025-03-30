package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Organization;

public interface OrganizationRepository extends JpaRepository<Organization, Integer> {
}
