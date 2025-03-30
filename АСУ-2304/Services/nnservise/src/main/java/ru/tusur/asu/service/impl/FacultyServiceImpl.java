package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Faculty;
import ru.tusur.asu.repository.FacultyRepository;
import ru.tusur.asu.service.FacultyService;

import java.util.List;

@Service
public class FacultyServiceImpl implements FacultyService {

    @Autowired
    private FacultyRepository facultyRepository;

    @Override
    public void create(Faculty faculty) {
        facultyRepository.save(faculty);
    }

    @Override
    public List<Faculty> readAll() {
        return facultyRepository.findAll();
    }

    @Override
    public Faculty read(Integer id) {
        return facultyRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Faculty faculty, Integer id) {
        if (!facultyRepository.existsById(id)) {
            return false;
        }

        faculty.setId(id);
        facultyRepository.save(faculty);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!facultyRepository.existsById(id)) {
            return false;
        }

        facultyRepository.deleteById(id);

        return true;
    }
}
