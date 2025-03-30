package ru.tusur.asu.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ru.tusur.asu.model.Profile;

public interface ProfileRepository extends JpaRepository<Profile, Integer> {
}
