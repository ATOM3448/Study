package ru.tusur.asu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.tusur.asu.model.Profile;
import ru.tusur.asu.service.ProfileService;

import java.util.List;

@RestController
public class MyProfileController {
    private static final String mapping = "/api/profiles";

    private final ProfileService profileService;

    @Autowired
    public MyProfileController(ProfileService profileService) {
        this.profileService = profileService;
    }

    @GetMapping(value = mapping + "/{id}")
    public ResponseEntity<Profile> read(@PathVariable(name = "id") int id) {
        final Profile profile = profileService.read(id);

        return profile != null
                ? new ResponseEntity<>(profile, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = mapping)
    public ResponseEntity<List<Profile>> readAll() {
        final List<Profile> profiles = profileService.readAll();

        return profiles != null && !profiles.isEmpty()
                ? new ResponseEntity<>(profiles, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = mapping)
    public ResponseEntity<?> create(@RequestBody Profile profile) {
        profileService.create(profile);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }

    @PutMapping(value = mapping + "/{id}")
    public ResponseEntity<?> update(@PathVariable(name = "id") int id,
                                    @RequestBody Profile profile) {
        final boolean updated = profileService.update(profile, id);

        return updated
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }

    @DeleteMapping(value = mapping + "/{id}")
    public ResponseEntity<?> delete(@PathVariable(name = "id") int id) {
        final boolean deleted = profileService.delete(id);

        return deleted
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }
}
