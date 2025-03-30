package ru.tusur.asu.model;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;
import lombok.experimental.Accessors;
import org.hibernate.annotations.OnDelete;
import org.hibernate.annotations.OnDeleteAction;

@Getter
@Setter
@Accessors(chain=true)
@Entity
@Table(name = "INDICATOR")
public class Indicator {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    private Integer id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "group_id", foreignKey = @ForeignKey(name = "group_id"), nullable = false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    private IndicatorGroup indicatorGroup;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "discipline_id", foreignKey = @ForeignKey(name = "discipline_id"), nullable = false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    private Discipline discipline;

    @Column(name = "name", nullable = false)
    private String name;

    @Column(name = "max_value", nullable = false)
    private Integer maxValue;
}
