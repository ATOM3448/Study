package ru.tusur.asu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.tusur.asu.model.Faculty;
import ru.tusur.asu.service.FacultyService;

import java.util.List;

@RestController
public class FacultyController {
    private static final String mapping = "/api/faculties";

    private final FacultyService facultyService;

    @Autowired
    public FacultyController(FacultyService facultyService) {
        this.facultyService = facultyService;
    }

    @GetMapping(value = mapping + "/{id}")
    public ResponseEntity<Faculty> read(@PathVariable(name = "id") int id) {
        final Faculty faculty = facultyService.read(id);

        return faculty != null
                ? new ResponseEntity<>(faculty, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = mapping)
    public ResponseEntity<List<Faculty>> readAll() {
        final List<Faculty> faculties = facultyService.readAll();

        return faculties != null && !faculties.isEmpty()
                ? new ResponseEntity<>(faculties, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = mapping)
    public ResponseEntity<?> create(@RequestBody Faculty faculty) {
        facultyService.create(faculty);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }

    @PutMapping(value = mapping + "/{id}")
    public ResponseEntity<?> update(@PathVariable(name = "id") int id,
                                    @RequestBody Faculty faculty) {
        final boolean updated = facultyService.update(faculty, id);

        return updated
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }

    @DeleteMapping(value = mapping + "/{id}")
    public ResponseEntity<?> delete(@PathVariable(name = "id") int id) {
        final boolean deleted = facultyService.delete(id);

        return deleted
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }
}
