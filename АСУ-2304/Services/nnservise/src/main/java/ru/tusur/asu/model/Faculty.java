package ru.tusur.asu.model;

import com.fasterxml.jackson.annotation.*;
import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;
import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;
import lombok.experimental.Accessors;
import org.hibernate.annotations.OnDelete;
import org.hibernate.annotations.OnDeleteAction;
import ru.tusur.asu.model.deserializer.FacultyDeserializer;
import ru.tusur.asu.model.serializer.FacultySerializer;

@Getter
@Setter
@Accessors(chain=true)
@Entity
@Table(name = "FACULTY", uniqueConstraints = {@UniqueConstraint(columnNames = {"organization_id", "name"})})
@JsonSerialize(using = FacultySerializer.class)
@JsonDeserialize(using = FacultyDeserializer.class)
public class Faculty {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    private Integer id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "organization_id", foreignKey = @ForeignKey(name = "organization_id"), nullable = false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    @JsonFormat()
    private Organization organization;

    @Column(name = "name", nullable = false)
    private String name;
}
