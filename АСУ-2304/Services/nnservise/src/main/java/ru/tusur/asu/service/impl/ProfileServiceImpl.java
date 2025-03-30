package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Profile;
import ru.tusur.asu.repository.ProfileRepository;
import ru.tusur.asu.service.ProfileService;

import java.util.List;

@Service
public class ProfileServiceImpl implements ProfileService {

    @Autowired
    private ProfileRepository profileRepository;

    @Override
    public void create(Profile profile) {
        profileRepository.save(profile);
    }

    @Override
    public List<Profile> readAll() {
        return profileRepository.findAll();
    }

    @Override
    public Profile read(Integer id) {
        return profileRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Profile profile, Integer id) {
        if (!profileRepository.existsById(id)) {
            return false;
        }

        profile.setId(id);
        profileRepository.save(profile);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!profileRepository.existsById(id)) {
            return false;
        }

        profileRepository.deleteById(id);

        return true;
    }
}
