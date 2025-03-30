package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Teacher;
import ru.tusur.asu.repository.TeacherRepository;
import ru.tusur.asu.service.TeacherService;

import java.util.List;

@Service
public class TeacherServiceImpl implements TeacherService {

    @Autowired
    private TeacherRepository teacherRepository;

    @Override
    public void create(Teacher teacher) {
        teacherRepository.save(teacher);
    }

    @Override
    public List<Teacher> readAll() {
        return teacherRepository.findAll();
    }

    @Override
    public Teacher read(Integer id) {
        return teacherRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Teacher teacher, Integer id) {
        if (!teacherRepository.existsById(id)) {
            return false;
        }

        teacher.setId(id);
        teacherRepository.save(teacher);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!teacherRepository.existsById(id)) {
            return false;
        }

        teacherRepository.deleteById(id);

        return true;
    }
}
