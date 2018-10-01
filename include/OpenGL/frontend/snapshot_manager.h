/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_SNAPSHOT_MANAGER_H
#define VKGL_SNAPSHOT_MANAGER_H

#include "OpenGL/types.h"
#include <map>

namespace OpenGL
{
    class ISnapshotManagerReference
    {
    public:
        virtual ~ISnapshotManagerReference()
        {
            /* Stub */
        }

        virtual void on_reference_created  (const OpenGL::GLReference* in_reference_ptr) = 0;
        virtual void on_reference_destroyed(const OpenGL::GLReference* in_reference_ptr) = 0;
    };

    class SnapshotManager : public ISnapshotManagerReference
    {
    public:
        /* Public functions */
        SnapshotManager(const GLuint&             in_object_id,
                        IStateSnapshotAccessors*  in_state_snapshot_accesors_ptr,
                        const OpenGL::TimeMarker& in_start_time_marker,
                        std::function<void()>     in_on_all_references_deleted_func);

        OpenGL::GLReferenceUniquePtr acquire_reference(const OpenGL::TimeMarker& in_time_marker);

        const OpenGL::TimeMarker& get_last_modified_time() const
        {
            return m_last_modified_time;
        }

        uint32_t get_n_references(const bool& in_include_tot_snapshot_references) const;
        uint32_t get_n_snapshots () const
        {
            return static_cast<uint32_t>(m_snapshots.size() );
        }

        const void* get_readonly_snapshot    (const OpenGL::TimeMarker& in_time_marker) const;
        void*       get_rw_tot_snapshot      ();
        void        update_last_modified_time();

    private:
        /* Private type definitions */
        typedef struct
        {
            std::unique_ptr<void, std::function<void(void*)> > internal_data_ptr;
            std::vector<const GLReference*>                    references;
        } StateSnapshot;
        typedef std::unique_ptr<StateSnapshot> StateSnapshotUniquePtr;

        /* ISnapshotManagerReference */

        void on_reference_created  (const OpenGL::GLReference* in_reference_ptr) final;
        void on_reference_destroyed(const OpenGL::GLReference* in_reference_ptr) final;

        /* Private variables */
        OpenGL::TimeMarker                                   m_last_modified_time;
        mutable std::mutex                                   m_mutex;
        const GLuint                                         m_object_id;
        std::unique_ptr<void, std::function<void(void*)> >   m_scratch_snapshot_ptr;
        std::map<OpenGL::TimeMarker, StateSnapshotUniquePtr> m_snapshots;
        std::vector<const GLReference*>                      m_tot_snapshot_references;

        std::function<void()>    m_on_all_references_deleted_func;
        IStateSnapshotAccessors* m_state_snapshot_accesors_ptr;

        friend class OpenGL::GLObjectManager;
    };
};

#endif /* VKGL_SNAPSHOT_MANAGER_H */