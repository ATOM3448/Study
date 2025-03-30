package ru.tusur.asu.model.serializer;

import com.fasterxml.jackson.core.JsonGenerator;
import com.fasterxml.jackson.databind.JsonSerializer;
import com.fasterxml.jackson.databind.SerializerProvider;
import ru.tusur.asu.model.Faculty;

import java.io.IOException;

public class FacultySerializer extends JsonSerializer<Faculty> {
    @Override
    public void serialize(Faculty faculty, JsonGenerator jsonGenerator,
                          SerializerProvider serializerProvider) throws IOException {
        jsonGenerator.writeStartObject();

        jsonGenerator.writeNumberField("id", faculty.getId());
        jsonGenerator.writeNumberField("organization_id", faculty.getOrganization().getId());
        jsonGenerator.writeStringField("name", faculty.getName());

        jsonGenerator.writeEndObject();
    }
}
